#include "logic/include/JSON_data_types/complex/Object.h"
#include "logic/include/exception/JSON_DT/ObjectException.h"
#include "logic/include/utils/JSON.h"
#include "logic/include/syntax_config.h"

size_t Object::fromStdString(const std::string &string)
{
    size_t char_consumed = 0;
    setEndPos(getBeginPos());

    if (string[0] != OBJECT_BORDER_BEGIN[0]) {
        throw ObjectBracketBeginException("no begin bracket found", getEndPos());
    }
    char_consumed++;

    bool end_found = false;
    bool comma_found = true;
    for (size_t i = char_consumed; i < string.size(); i++) {
        getEndPos().setColumn(getEndPos().getColumn() + 1);
        if (string[i] == DEFAULT_VALUE_SEPARATOR[0]) {
            if (comma_found) {
                throw ObjectUnexpectedException(string[i], getEndPos());
            }
            comma_found = true;
        } else {
            comma_found = false;
            if (string[i] == STRING_BORDER[0]) {
                instance_.push_back(std::make_unique<KeyValuePair>());
                instance_[instance_.size() - 1]->setBeginPos(getEndPos());
                i += instance_[instance_.size() - 1]->fromStdString(string.substr(i));
                setEndPos(instance_[instance_.size() - 1]->getEndPos());
                i--;
            } else if (string[i] == OBJECT_BORDER_END[0]) {
                end_found = true;
                char_consumed = i + 1;
                break;
            } else if (string[i] == DEFAULT_LINE_SEPARATOR[0]) {
                getEndPos().setRow(getEndPos().getRow() + 1);
                getEndPos().setColumn(-1);
            } else if (isJSONIgnored(string[i])) {
                continue;
            } else {
                throw ObjectUnexpectedException(string[i], getEndPos());
            }
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
