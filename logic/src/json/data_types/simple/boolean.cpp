#include "logic/include/json/data_types/simple/boolean.h"
#include "logic/include/json/exception/booleanexception.h"
#include "logic/include/json/syntax/charsets/dt/booleancharset.h"

#include <cstring>

size_t Boolean::fromStdString(const std::string &string) {
    setEndPos(getBeginPos());

    size_t char_consumed = 0;

    if (!std::strncmp(string.data(), BooleanCharSet::getTrue().data(),
                      BooleanCharSet::getTrue().size())) {
        instance_ = true;
        char_consumed = BooleanCharSet::getTrue().size();
    } else if (!std::strncmp(string.data(), BooleanCharSet::getFalse().data(),
                             BooleanCharSet::getFalse().size())) {
        instance_ = false;
        char_consumed = BooleanCharSet::getFalse().size();
    } else {
        throw BooleanUnexpectedException(string[0], getEndPos());
    }

    getEndPos().setColumn(getEndPos().getColumn() + char_consumed - 1);
    return char_consumed;
}

std::string Boolean::toStdString() {
    return BooleanCharSet::toStdString(instance_);
}

std::vector<TextElement> Boolean::toTextElements(Indent indent) {
    return {TextElement(toStdString(), indent, BOOLEAN_F)};
}
