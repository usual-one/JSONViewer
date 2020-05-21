#include "logic/include/json/data_types/dt_headers.h"
#include "logic/include/json/exception/arrayexception.h"
#include "logic/include/json/syntax.h"
#include "logic/include/json/jsonparser.h"

size_t Array::fromStdString(const std::string &string) {
    size_t char_consumed = 0;
    setEndPos(getBeginPos());

    JSONParser parser;

    if (!parser.startsLike(string, ARRAY_DT)) {
        throw ArrayBracketBeginException("no begin bracket found", getEndPos());
    }
    char_consumed += ARRAY_BORDER_BEGIN.size();

    bool end_found = false;
    bool separator_found = true;
    for (size_t i = char_consumed; i < string.size(); i++) {
        getEndPos().nextCharacter();
        if (parser.isValueSeparator(std::string(1, string[i]))) {
            if (separator_found) {
                throw ArrayUnexpectedException(string[i], getEndPos());
            }
            separator_found = true;
            continue;
        }
        separator_found = false;
        if (parser.canJSONStartWith(string[i])) {
            instance_.push_back(parser.createFromStartStr(string.substr(i)));
            instance_[instance_.size() - 1]->setBeginPos(getEndPos());
            i += instance_[instance_.size() - 1]->fromStdString(string.substr(i));
            setEndPos(instance_[instance_.size() - 1]->getEndPos());
            i--;
            continue;
        } else if (parser.endsLike(string.substr(0, i + 1), ARRAY_DT)) {
            end_found = true;
            char_consumed = i + 1;
            break;
        } else if (parser.isLineSeparator(std::string(1, string[i]))) {
            getEndPos().nextLine();
        } else if (parser.isJSONIgnored(string[i])) {
            continue;
        } else {
            throw ArrayUnexpectedException(string[i], getEndPos());
        }
    }

    if (!end_found) {
        throw ArrayBracketEndException("no end bracket found", getEndPos());
    }

    return char_consumed;
}

std::string Array::toStdString() {
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
