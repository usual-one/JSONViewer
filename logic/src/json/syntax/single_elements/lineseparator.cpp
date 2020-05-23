#include "logic/include/json/syntax/single_elements/lineseparator.h"
#include "logic/include/json/syntax/syntax.h"

std::string LineSeparator::instance_ = DEFAULT_LINE_SEPARATOR;

std::string LineSeparator::toStdString() {
    return instance_;
}

void LineSeparator::setInstance(const std::string &value) {
    instance_ = value;
}

bool LineSeparator::isEqual(const std::string &other) {
    return other == instance_;
}

bool LineSeparator::isEqual(char other) {
    return instance_.size() == 1 && instance_[0] == other;
}
