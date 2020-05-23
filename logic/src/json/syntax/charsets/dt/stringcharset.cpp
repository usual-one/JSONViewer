#include "logic/include/json/syntax/charsets/dt/stringcharset.h"
#include "logic/include/json/syntax/syntax.h"

std::string StringCharSet::border_ = STRING_BORDER;

std::string StringCharSet::getBorder() {
    return border_;
}

void StringCharSet::setBorder(const std::string &value) {
    border_ = value;
}

