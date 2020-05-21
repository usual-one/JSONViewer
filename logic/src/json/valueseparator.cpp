#include "logic/include/json/syntax/valueseparator.h"
#include "logic/include/json/syntax.h"

ValueSeparator::ValueSeparator() {
    setInstance(DEFAULT_VALUE_SEPARATOR);
    needed_ = false;;
}

std::string ValueSeparator::toStdString() {
    return instance_;
}

bool ValueSeparator::isNeeded() {
    return needed_;
}

void ValueSeparator::setNeeded(bool value) {
    needed_ = value;
}

void ValueSeparator::setInstance(const std::string &value) {
    instance_ = value;
}
