#include "logic/include/json/syntax/single_elements/spacesyntaxelement.h"
#include "logic/include/json/syntax/syntax.h"

std::string SpaceSyntaxElement::instance_ = DEFAULT_SPACE;

std::string SpaceSyntaxElement::toStdString() {
    return instance_;
}

void SpaceSyntaxElement::setInstance(const std::string &value) {
    instance_ = value;
}

bool SpaceSyntaxElement::isEqual(const std::string &other) {
    return other == instance_;
}

bool SpaceSyntaxElement::isEqual(char other) {
    return instance_.size() == 1 && instance_[0] == other;
}
