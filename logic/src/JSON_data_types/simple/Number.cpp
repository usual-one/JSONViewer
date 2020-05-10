#include "logic/include/JSON_data_types/simple/Number.h"
#include "logic/include/exception/JSON_DT/NumberException.h"
#include "logic/include/utils/JSON.h"

size_t Number::fromStdString(const std::string &string)
{
    setEndPos(getBeginPos());
    std::string number;
    number.clear();

    bool e_found = false;
    bool dot_found = false;

    for (size_t i = 0; i < string.size(); i++) {
        if (!isFromJSONNumber(string[i])) {
            break;
        } else if (isUnarySignChar(string[i])) {
            if (!i) {
                number.append(1, string[i]);
            } else if (isEulersNumberChar(string[i - 1])) {
                number.append(1, string[i]);
            } else {
                throw NumberUnexpectedException(string[i], getEndPos());
            }
        } else if (isEulersNumberChar(string[i])) {
            if (e_found) {
                throw NumberUnexpectedException(string[i], getEndPos());
            } else {
                number.append(1, string[i]);
                e_found = true;
            }
        } else if (string[i] == '.') {
            if (dot_found) {
                throw NumberUnexpectedException(string[i], getEndPos());
            } else if (!i || isUnarySignChar(string[i - 1])) {
                throw NumberUnexpectedException(string[i], getEndPos());
            } else {
                number.append(1, string[i]);
                dot_found = true;
            }
        } else if (string[i] == '0') {
            if (!i || isUnarySignChar(string[i - 1])) {
                if (i == string.size() - 1) {
                    number.append(1, string[i]);
                } else if (string[i + 1] == '.' || !isFromJSONNumber(string[i + 1])) {
                    number.append(1, string[i]);
                } else {
                    throw NumberUnexpectedException(string[i], getEndPos());
                }

            }
        } else if (isdigit(string[i])) {
            number.append(1, string[i]);
        }

    }

    getEndPos().setColumn(getEndPos().getColumn() + number.size() - 1);
    if (!number.size()) {
        throw NumberEmptyException("number is empty", getEndPos());
    }

    instance_ = std::stod(number);

    return number.size();
}


std::string Number::toStdString(const std::string &prefix)
{
    return prefix + std::to_string(instance_);
}
