#include "logic/include/json/syntax/single_elements/keyvalueseparator.h"
#include "logic/include/json/syntax/syntax.h"

std::string KeyValueSeparator::instance_ = KEY_VALUE_SEPARATOR;

std::string KeyValueSeparator::toStdString() {
    return instance_;
}

void KeyValueSeparator::setInstance(const std::string &value) {
    instance_ = value;
}

bool KeyValueSeparator::isEqual(const std::string &other) {
    return other == instance_;
}

bool KeyValueSeparator::isEqual(char other) {
    return instance_.size() == 1 && instance_[0] == other;
}
