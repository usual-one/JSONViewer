#include "logic/include/json/syntax/single_elements/indentsyntaxelement.h"
#include "logic/include/json/syntax/syntax.h"

std::string IndentSyntaxElement::instance_ = DEFAULT_INDENT;

std::string IndentSyntaxElement::toStdString() {
    return instance_;
}

void IndentSyntaxElement::setInstance(const std::string &value) {
    instance_ = value;
}

bool IndentSyntaxElement::isEqual(const std::string &other) {
    return instance_ == other;
}

bool IndentSyntaxElement::isEqual(char other) {
    return instance_.size() == 1 && instance_[0] == other;
}
