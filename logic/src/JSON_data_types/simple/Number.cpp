#include "logic/include/JSON_data_types/simple/Number.h"
#include "logic/include/exception/JSON_DT/NumberException.h"
#include "logic/include/utils/JSON.h"

size_t Number::fromStdString(const std::string &string) {
    setEndPos(getBeginPos());
    in_text_.clear();

    bool e_found = false;
    bool dot_found = false;

    for (size_t i = 0; i < string.size(); i++) {
        if (!isFromJSONNumber(string[i])) {
            break;
        } else if (isUnarySignChar(string[i])) {
            if (!i) {
                in_text_.append(1, string[i]);
            } else if (isEulersNumberChar(string[i - 1])) {
                in_text_.append(1, string[i]);
            } else {
                throw NumberUnexpectedException(string[i], getEndPos());
            }
        } else if (isEulersNumberChar(string[i])) {
            if (e_found) {
                throw NumberUnexpectedException(string[i], getEndPos());
            } else {
                in_text_.append(1, string[i]);
                e_found = true;
            }
        } else if (string[i] == '.') {
            if (dot_found) {
                throw NumberUnexpectedException(string[i], getEndPos());
            } else if (!i || isUnarySignChar(string[i - 1])) {
                throw NumberUnexpectedException(string[i], getEndPos());
            } else {
                in_text_.append(1, string[i]);
                dot_found = true;
            }
        } else if (string[i] == '0') {
            if (!i || isUnarySignChar(string[i - 1])) {
                if (i == string.size() - 1) {
                    in_text_.append(1, string[i]);
                } else if (string[i + 1] == '.' || !isFromJSONNumber(string[i + 1])) {
                    in_text_.append(1, string[i]);
                } else {
                    throw NumberUnexpectedException(string[i], getEndPos());
                }

            } else {
                in_text_.append(1, string[i]);
            }
        } else if (isdigit(string[i])) {
            in_text_.append(1, string[i]);
        }

    }

    getEndPos().setColumn(getEndPos().getColumn() + in_text_.size() - 1);
    if (!in_text_.size()) {
        throw NumberEmptyException("number is empty", getEndPos());
    }


    instance_ = std::stod(in_text_);

    return in_text_.size();
}

std::string Number::toStdString() {
    return in_text_;
}

std::vector<TextElement> Number::toTextElements(Indent indent) {
    return {TextElement(toStdString(), indent, NUMBER_F)};
}
