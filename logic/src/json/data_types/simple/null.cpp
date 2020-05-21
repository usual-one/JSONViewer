#include "logic/include/json/data_types/simple/null.h"
#include "logic/include/json/exception/nullexception.h"
#include "logic/include/json/syntax.h"

#include <cstring>

size_t Null::fromStdString(const std::string &string) {
    setEndPos(getBeginPos());
    size_t char_consumed = 0;

    if (!std::strncmp(string.data(), NULL_VALUE.data(), NULL_VALUE.size())) {
        char_consumed = NULL_VALUE.size();
    } else {
        throw NullUnexpectedException(string[0], getEndPos());
    }

    getEndPos().setColumn(getEndPos().getColumn() + char_consumed - 1);
    return char_consumed;
}

std::string Null::toStdString() {
    return NULL_VALUE;
}

std::vector<TextElement> Null::toTextElements(Indent indent) {
    return {TextElement(toStdString(), indent, NULL_F)};
}
