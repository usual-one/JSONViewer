#include "logic/include/json/data_types/complex/object.h"
#include "logic/include/json/exception/objectexception.h"
#include "logic/include/json/syntax.h"
#include "logic/include/json/jsonparser.h"
#include "logic/include/json/syntax/valueseparator.h"

size_t Object::fromStdString(const std::string &string) {
    size_t char_consumed = 0;
    setEndPos(getBeginPos());

    JSONParser parser;

    if (!parser.startsLike(string, OBJECT_DT)) {
        throw ObjectBracketBeginException("no begin bracket found", getEndPos());
    }
    char_consumed += OBJECT_BORDER_BEGIN.size();

    ValueSeparator value_separator;
    bool end_found = false;
    for (size_t i = char_consumed; i < string.size(); i++) {
        getEndPos().nextCharacter();
        if (parser.isValueSeparator(std::string(1, string[i]))) {
            if (!value_separator.isNeeded()) {
                throw ObjectUnexpectedException(string[i], getEndPos());
            }
            value_separator.setNeeded(false);
            continue;
        }
        if (parser.startsLike(string.substr(i), STRING_DT)) {
            if (value_separator.isNeeded()) {
                throw ObjectUnexpectedException(string[i], getEndPos());
            }
            instance_.push_back(std::make_unique<KeyValuePair>());
            instance_[instance_.size() - 1]->setBeginPos(getEndPos());
            i += instance_[instance_.size() - 1]->fromStdString(string.substr(i));
            setEndPos(instance_[instance_.size() - 1]->getEndPos());
            i--;
            value_separator.setNeeded(true);
        } else if (parser.endsLike(string.substr(0, i + 1), OBJECT_DT)) {
            end_found = true;
            char_consumed = i + 1;
            break;
        } else if (parser.isLineSeparator(std::string(1, string[i]))) {
            getEndPos().nextLine();
        } else if (parser.isJSONIgnored(string[i])) {
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
    std::string str = OBJECT_BORDER_BEGIN;
    for (size_t i = 0; i < instance_.size() - 1; i++) {
        str.append(DEFAULT_LINE_SEPARATOR);
        str.append(instance_[i]->toStdString());
        str.append(DEFAULT_VALUE_SEPARATOR);
    }
    if (instance_.size()) {
        str.append(DEFAULT_LINE_SEPARATOR);
        str.append(instance_[instance_.size() - 1]->toStdString());
        str.append(DEFAULT_LINE_SEPARATOR);
    }
    str.append(OBJECT_BORDER_END);
    return str;
}

std::vector<TextElement> Object::toTextElements(Indent indent) {
    std::vector<TextElement> elements = {};
    elements.push_back(TextElement(OBJECT_BORDER_BEGIN, Indent(indent.begin_)));
    for (size_t i = 0; i < instance_.size(); i++) {
        elements.push_back(TextElement(DEFAULT_LINE_SEPARATOR));
        std::vector<TextElement> el_elements = instance_[i]->toTextElements(Indent(indent.end_ + DEFAULT_INDENT));
        elements.insert(elements.end(), el_elements.begin(), el_elements.end());
        elements.push_back(TextElement(DEFAULT_VALUE_SEPARATOR));
    }
    if (instance_.size()) {
        elements.pop_back();
        elements.push_back(TextElement(DEFAULT_LINE_SEPARATOR));
        elements.push_back(TextElement(OBJECT_BORDER_END, Indent(indent.end_)));
    } else {
        elements.push_back(TextElement(OBJECT_BORDER_END));
    }
    return elements;
}
