#include "logic/include/json/syntax/charsets/dt/objectcharset.h"
#include "logic/include/json/syntax/syntax.h"

std::vector<std::string> ObjectCharSet::borders_ = OBJECT_BORDERS;

std::vector<std::string> ObjectCharSet::getBorders() {
    return borders_;
}

void ObjectCharSet::setBorders(const std::vector<std::string> &value) {
    borders_ = value;
}
