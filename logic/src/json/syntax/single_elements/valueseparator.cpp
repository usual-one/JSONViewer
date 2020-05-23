#include "logic/include/json/syntax/single_elements/valueseparator.h"
#include "logic/include/json/syntax/syntax.h"

std::string ValueSeparator::instance_ = DEFAULT_VALUE_SEPARATOR;

ValueSeparator::ValueSeparator() {
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

bool ValueSeparator::isEqual(const std::string &other) {
    return other == instance_;
}

bool ValueSeparator::isEqual(char other) {
    return instance_.size() == 1 && instance_[0] == other;
}


