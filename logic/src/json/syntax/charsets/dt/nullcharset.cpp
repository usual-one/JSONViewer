#include "logic/include/json/syntax/charsets/dt/nullcharset.h"
#include "logic/include/json/syntax/syntax.h"

std::string NullCharSet::value_ = NULL_VALUE;

std::string NullCharSet::toStdString() {
    return value_;
}

void NullCharSet::setValue(const std::string &value) {
    value_ = value;
}
