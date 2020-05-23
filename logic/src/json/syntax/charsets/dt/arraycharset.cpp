#include "logic/include/json/syntax/charsets/dt/arraycharset.h"
#include "logic/include/json/syntax/syntax.h"

std::vector<std::string> ArrayCharSet::borders_ = ARRAY_BORDERS;

std::vector<std::string> ArrayCharSet::getBorders() {
    return borders_;
}

void ArrayCharSet::setBorders(const std::vector<std::string> &value) {
    borders_ = value;
}
