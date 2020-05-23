#include "logic/include/json/syntax/charsets/ignoredcharset.h"
#include "logic/include/json/syntax/single_elements/lineseparator.h"

#include <cctype>

bool IgnoredCharSet::isInside(char other) {
    return std::isblank(other) || LineSeparator::isEqual(other) || other == '\r';
}
