#include "logic/include/JSON_data_types/complex/KeyValuePair.h"
#include "logic/include/exception/JSON_DT/KeyValuePairException.h"
#include "logic/include/JSON_data_types/DT_headers.h"
#include "logic/include/utils/JSON.h"

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
        if (string[i] == '\n') {
            getEndPos().setRow(getEndPos().getRow() + 1);
            getEndPos().setColumn(-1);
        } else if (isJSONIgnored(string[i])) {
            continue;
        } else if (string[i] == ':') {
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
            if (string[i] == '[') {
                value_ = std::make_unique<Array>();
            } else if (string[i] == '{') {
                value_ = std::make_unique<Object>();
            } else if (string[i] == '"') {
                value_ = std::make_unique<String>();
            } else if (isBooleanStartedWith(string[i])) {
                value_ = std::make_unique<Boolean>();
            } else if (string[i] == 'n') {
                value_ = std::make_unique<Null>();
            } else if (isFromJSONNumber(string[i])) {
                value_ = std::make_unique<Number>();
            }
            value_->setBeginPos(getEndPos());
            char_consumed = i + value_->fromStdString(string.substr(i));
            setEndPos(value_->getEndPos());
            break;
        } else {
            if (string[i] == '\n') {
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
    return key_->toStdString() + ": " + value_->toStdString();
}

void KeyValuePair::printOnWidget(TextHighlighter &highlighter, const std::string &prefix) {
    highlighter.printKey((prefix + key_->toStdString()).data());
    highlighter.print(": ");
    value_->printOnWidget(highlighter);
}

std::unique_ptr<String> &KeyValuePair::getKey() {
    return key_;
}

std::unique_ptr<JSONDT> &KeyValuePair::getValue() {
    return value_;
}
