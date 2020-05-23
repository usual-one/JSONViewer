#include "logic/include/json/data_types/simple/number.h"
#include "logic/include/json/exception/numberexception.h"
#include "logic/include/json/syntax/charsets/dt/numbercharset.h"

size_t Number::fromStdString(const std::string &string) {
    setEndPos(getBeginPos());
    in_text_.clear();

    NumberCharSet number_char_set;

    for (size_t i = 0; i < string.size(); i++) {
        if (!NumberCharSet::isInside(string[i])) {
            break;
        } else if (NumberCharSet::isUnarySign(string[i])) {
            if (!i) {
                in_text_.append(1, string[i]);
            } else if (NumberCharSet::isEulersNumber(string[i - 1])) {
                in_text_.append(1, string[i]);
            } else {
                throw NumberUnexpectedException(string[i], getEndPos());
            }
        } else if (NumberCharSet::isEulersNumber(string[i])) {
            if (number_char_set.isEulersNumberFound()) {
                throw NumberUnexpectedException(string[i], getEndPos());
            } else {
                in_text_.append(1, string[i]);
                number_char_set.setEulersNumberFound(true);
            }
        } else if (NumberCharSet::isDecimalSeparator(string[i])) {
            if (number_char_set.isDecimalSeparatorFound()) {
                throw NumberUnexpectedException(string[i], getEndPos());
            } else if (!i || NumberCharSet::isUnarySign(string[i - 1])) {
                throw NumberUnexpectedException(string[i], getEndPos());
            } else {
                in_text_.append(1, string[i]);
                number_char_set.setDecimalSeparatorFound(true);
            }
        } else if (string[i] == '0') {
            if (!i || NumberCharSet::isUnarySign(string[i - 1])) {
                if (i == string.size() - 1) {
                    in_text_.append(1, string[i]);
                } else if (NumberCharSet::isDecimalSeparator(string[i + 1]) ||
                           !NumberCharSet::isInside(string[i + 1])) {
                    in_text_.append(1, string[i]);
                } else {
                    throw NumberUnexpectedException(string[i], getEndPos());
                }

            } else {
                in_text_.append(1, string[i]);
            }
        } else if (NumberCharSet::isDigit(string[i])) {
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
