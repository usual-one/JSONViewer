#include "logic/include/json/syntax/charsets/dt/numbercharset.h"
#include "logic/include/json/syntax/syntax.h"

std::set<std::string> NumberCharSet::unary_signs_ = UNARY_SIGNS;

std::set<std::string> NumberCharSet::eulers_number_ = EULERS_NUMBER;

std::string NumberCharSet::decimal_separator_ = DECIMAL_SEPARATOR;

NumberCharSet::NumberCharSet() {
    eulers_number_found_ = false;
    decimal_separator_found_ = false;
}

bool NumberCharSet::isEulersNumberFound() {
    return eulers_number_found_;
}

bool NumberCharSet::isDecimalSeparatorFound() {
    return decimal_separator_found_;
}

void NumberCharSet::setEulersNumberFound(bool value) {
    eulers_number_found_ = value;
}

void NumberCharSet::setDecimalSeparatorFound(bool value) {
    decimal_separator_found_ = value;
}

bool NumberCharSet::isInside(char other) {
    return isDigit(other) || isUnarySign(other) ||
            isEulersNumber(other) || isDecimalSeparator(other);
}

bool NumberCharSet::isDigit(char other) {
    return std::isdigit(other);
}

bool NumberCharSet::isUnarySign(char other) {
    return unary_signs_.count(std::string(1, other));
}

bool NumberCharSet::isEulersNumber(char other) {
    return unary_signs_.count(std::string(1, other));
}

bool NumberCharSet::isDecimalSeparator(char other) {
    return decimal_separator_.size() == 1 && decimal_separator_[0] == other;
}

