#include "logic/include/json/data_types/complex/object.h"
#include "logic/include/json/exception/objectexception.h"
#include "logic/include/json/syntax/single_elements/valueseparator.h"
#include "logic/include/json/syntax/single_elements/lineseparator.h"
#include "logic/include/json/syntax/single_elements/indentsyntaxelement.h"
#include "logic/include/json/data_types/complex/inner/keyvaluepair.h"
#include "logic/include/json/syntax/charsets/dt/dtcharset.h"
#include "logic/include/json/syntax/charsets/dt/objectcharset.h"
#include "logic/include/json/syntax/charsets/ignoredcharset.h"

size_t Object::fromStdString(const std::string &string) {
    size_t char_consumed = 0;
    setEndPos(getBeginPos());

    if (!DTCharSet::startsLike(string, OBJECT_DT)) {
        throw ObjectBracketBeginException("no begin bracket found", getEndPos());
    }
    char_consumed += ObjectCharSet::getBorders()[0].size();

    ValueSeparator value_separator;
    bool end_found = false;
    for (size_t i = char_consumed; i < string.size(); i++) {
        getEndPos().nextCharacter();
        if (ValueSeparator::isEqual(string[i])) {
            if (!value_separator.isNeeded()) {
                throw ObjectUnexpectedException(string[i], getEndPos());
            }
            value_separator.setNeeded(false);
            continue;
        }
        if (DTCharSet::startsLike(string.substr(i), STRING_DT)) {
            if (value_separator.isNeeded()) {
                throw ObjectUnexpectedException(string[i], getEndPos());
            }
            instance_.push_back(std::make_unique<KeyValuePair>());
            instance_[instance_.size() - 1]->setBeginPos(getEndPos());
            i += instance_[instance_.size() - 1]->fromStdString(string.substr(i));
            setEndPos(instance_[instance_.size() - 1]->getEndPos());
            i--;
            value_separator.setNeeded(true);
        } else if (DTCharSet::endsLike(string.substr(0, i + 1), OBJECT_DT)) {
            end_found = true;
            char_consumed = i + 1;
            break;
        } else if (LineSeparator::isEqual(string[i])) {
            getEndPos().nextLine();
        } else if (IgnoredCharSet::isInside(string[i])) {
            continue;
        } else {
            throw ObjectUnexpectedException(string[i], getEndPos());
        }

    }

    if (!end_found) {
        throw ObjectBracketEndException("no end bracket found", getEndPos());
    }

    return char_consumed;
}

std::string Object::toStdString() {
    std::string str = ObjectCharSet::getBorders()[0];
    for (size_t i = 0; i < instance_.size() - 1; i++) {
        str.append(LineSeparator::toStdString());
        str.append(instance_[i]->toStdString());
        str.append(ValueSeparator::toStdString());
    }
    if (instance_.size()) {
        str.append(LineSeparator::toStdString());
        str.append(instance_[instance_.size() - 1]->toStdString());
        str.append(LineSeparator::toStdString());
    }
    str.append(ObjectCharSet::getBorders()[1]);
    return str;
}

std::vector<TextElement> Object::toTextElements(Indent indent) {
    std::vector<TextElement> elements = {};
    elements.push_back(TextElement(ObjectCharSet::getBorders()[0], Indent(indent.begin_)));
    for (size_t i = 0; i < instance_.size(); i++) {
        elements.push_back(TextElement(LineSeparator::toStdString()));
        std::vector<TextElement> el_elements = instance_[i]->toTextElements(
                    Indent(indent.end_ + IndentSyntaxElement::toStdString()));
        elements.insert(elements.end(), el_elements.begin(), el_elements.end());
        elements.push_back(TextElement(ValueSeparator::toStdString()));
    }
    if (instance_.size()) {
        elements.pop_back();
        elements.push_back(TextElement(LineSeparator::toStdString()));
        elements.push_back(TextElement(ObjectCharSet::getBorders()[1], Indent(indent.end_)));
    } else {
        elements.push_back(TextElement(ObjectCharSet::getBorders()[1]));
    }
    return elements;
}
