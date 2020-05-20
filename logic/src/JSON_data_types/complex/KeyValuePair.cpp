#include "logic/include/JSON_data_types/complex/KeyValuePair.h"
#include "logic/include/exception/JSON_DT/KeyValuePairException.h"
#include "logic/include/JSON_data_types/DT_headers.h"
#include "logic/include/syntax_config.h"
#include "logic/include/utils/JSON.h"
#include "logic/include/utils/string.h"

#include <QDebug>

KeyValuePair::KeyValuePair() {
    key_ = nullptr;
    value_ = nullptr;
}

size_t KeyValuePair::fromStdString(const std::string &string) {
    key_ = std::make_unique<String>();
    key_->setBeginPos(getBeginPos());
    size_t key_consumed = key_->fromStdString(string);

    setEndPos(key_->getEndPos());

    size_t separator_pos = string.size();
    for (size_t i = key_consumed; i < string.size(); i++) {
        getEndPos().setColumn(getEndPos().getColumn() + 1);
        if (string[i] == DEFAULT_LINE_SEPARATOR[0]) {
            getEndPos().setRow(getEndPos().getRow() + 1);
            getEndPos().setColumn(-1);
        } else if (isJSONIgnored(string[i])) {
            continue;
        } else if (string[i] == KEY_VALUE_PAIR_SEPARATOR[0]) {
            separator_pos = i;
            break;
        } else {
            throw KeyValuePairUnexpectedException(string[i], getEndPos());
        }
    }

    if (separator_pos == string.size()) {
        throw KeyValuePairNoSeparatorException("separator not found", getEndPos());
    }

    size_t char_consumed = separator_pos + 1;

    for (size_t i = char_consumed; i < string.size(); i++) {
        getEndPos().setColumn(getEndPos().getColumn() + 1);
        if (isJSONDTStartedWith(string[i])) {
            if (string[i] == ARRAY_BORDER_BEGIN[0]) {
                value_ = std::make_unique<Array>();
            } else if (string[i] == OBJECT_BORDER_BEGIN[0]) {
                value_ = std::make_unique<Object>();
            } else if (string[i] == STRING_BORDER[0]) {
                value_ = std::make_unique<String>();
            } else if (isBooleanStartedWith(string[i])) {
                value_ = std::make_unique<Boolean>();
            } else if (string[i] == NULL_VALUE[0]) {
                value_ = std::make_unique<Null>();
            } else if (isFromJSONNumber(string[i])) {
                value_ = std::make_unique<Number>();
            }
            value_->setBeginPos(getEndPos());
            char_consumed = i + value_->fromStdString(string.substr(i));
            setEndPos(value_->getEndPos());
            break;
        } else {
            if (string[i] == DEFAULT_LINE_SEPARATOR[0]) {
                getEndPos().setRow(getEndPos().getRow() + 1);
                getEndPos().setColumn(-1);
            } else if (isJSONIgnored(string[i])) {
                continue;
            } else {
                throw KeyValuePairUnexpectedException(string[i], getEndPos());
            }
        }
    }

    if (!value_) {
        throw KeyValuePairNoValueException("no value found", getEndPos());
    }

    return char_consumed;
}

std::string KeyValuePair::toStdString() {
    return key_->toStdString() + KEY_VALUE_PAIR_SEPARATOR + DEFAULT_SPACE + value_->toStdString();
}

std::vector<TextElement> KeyValuePair::toTextElements(Indent indent) {
    std::vector<TextElement> elements = {};
    elements.push_back(TextElement(key_->toStdString(), indent, KEY_F));
    elements.push_back(TextElement(KEY_VALUE_PAIR_SEPARATOR + DEFAULT_SPACE));

    std::vector value_elements = value_->toTextElements(Indent("", "", indent.own_));
    elements.insert(elements.end(), value_elements.begin(), value_elements.end());
    return elements;
}
