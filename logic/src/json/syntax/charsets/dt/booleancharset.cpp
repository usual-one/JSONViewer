#include "logic/include/json/syntax/charsets/dt/booleancharset.h"
#include "logic/include/json/syntax/syntax.h"

std::string BooleanCharSet::true_value_ = TRUE_VALUE;

std::string BooleanCharSet::false_value_ = FALSE_VALUE;

std::string BooleanCharSet::getTrue() {
    return true_value_;
}

std::string BooleanCharSet::getFalse() {
    return false_value_;
}

std::string BooleanCharSet::toStdString(bool value) {
    return value ? getTrue() : getFalse();
}

void BooleanCharSet::setTrueValue(const std::string &value) {
    true_value_ = value;
}

void BooleanCharSet::setFalseValue(const std::string &value) {
    false_value_ = value;
}
