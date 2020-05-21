#include "logic/include/json/data_types/dt_headers.h"
#include "logic/include/json/exception/arrayexception.h"
#include "logic/include/json/json.h"
#include "logic/include/json/syntax.h"

size_t Array::fromStdString(const std::string &string)
{
    size_t char_consumed = 0;
    setEndPos(getBeginPos());

    if (string[0] != ARRAY_BORDER_BEGIN[0]) {
        throw ArrayBracketBeginException("no begin bracket found", getEndPos());
    }
    char_consumed++;

    bool end_found = false;
    bool separator_found = true;
    for (size_t i = char_consumed; i < string.size(); i++) {
        getEndPos().setColumn(getEndPos().getColumn() + 1);
        if (string[i] == DEFAULT_VALUE_SEPARATOR[0]) {
            if (separator_found) {
                throw ArrayUnexpectedException(string[i], getEndPos());
            }
            separator_found = true;
        } else {
            separator_found = false;
            if (isJSONDTStartedWith(string[i])) {
                if (string[i] == ARRAY_BORDER_BEGIN[0]) {
                    instance_.push_back(std::make_unique<Array>());
                } else if (string[i] == OBJECT_BORDER_BEGIN[0]) {
                    instance_.push_back(std::make_unique<Object>());
                } else if (string[i] == STRING_BORDER[0]) {
                    instance_.push_back(std::make_unique<String>());
                } else if (isBooleanStartedWith(string[i])) {
                    instance_.push_back(std::make_unique<Boolean>());
                } else if (string[i] == NULL_VALUE[0]) {
                    instance_.push_back(std::make_unique<Null>());
                } else if (isFromJSONNumber(string[i])) {
                    instance_.push_back(std::make_unique<Number>());
                }
                instance_[instance_.size() - 1]->setBeginPos(getEndPos());
                i += instance_[instance_.size() - 1]->fromStdString(string.substr(i));
                setEndPos(instance_[instance_.size() - 1]->getEndPos());
                i--;
            } else {
                if (string[i] == ARRAY_BORDER_END[0]) {
                    end_found = true;
                    char_consumed = i + 1;
                    break;
                } else if (string[i] == DEFAULT_LINE_SEPARATOR[0]) {
                    getEndPos().setRow(getEndPos().getRow() + 1);
                    getEndPos().setColumn(-1);
                } else if (isJSONIgnored(string[i])) {
                    continue;
                } else {
                    throw ArrayUnexpectedException(string[i], getEndPos());
                }
            }
        }
    }

    if (!end_found) {
        throw ArrayBracketEndException("no end bracket found", getEndPos());
    }

    return char_consumed;
}

std::string Array::toStdString()
{
    std::string str = ARRAY_BORDER_BEGIN;
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
    str.append("}");
    return str;
}

std::vector<TextElement> Array::toTextElements(Indent indent) {
    std::vector<TextElement> elements = {};
    elements.push_back(TextElement(ARRAY_BORDER_BEGIN, Indent(indent.begin_)));
    for (size_t i = 0; i < instance_.size(); i++) {
        elements.push_back(TextElement(DEFAULT_LINE_SEPARATOR));
        std::vector<TextElement> el_elements = instance_[i]->toTextElements(Indent(indent.end_ + DEFAULT_INDENT));
        elements.insert(elements.end(), el_elements.begin(), el_elements.end());
        elements.push_back(TextElement(DEFAULT_VALUE_SEPARATOR));
    }
    if (instance_.size()) {
        elements.pop_back();
        elements.push_back(TextElement(DEFAULT_LINE_SEPARATOR));
        elements.push_back(TextElement(ARRAY_BORDER_END, Indent(indent.end_)));
    } else {
       elements.push_back(TextElement(ARRAY_BORDER_END));
    }
    return elements;
}
