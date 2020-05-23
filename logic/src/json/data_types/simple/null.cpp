#include "logic/include/json/data_types/simple/null.h"
#include "logic/include/json/exception/nullexception.h"
#include "logic/include/json/syntax/charsets/dt/nullcharset.h"

#include <cstring>

size_t Null::fromStdString(const std::string &string) {
    setEndPos(getBeginPos());
    size_t char_consumed = 0;

    if (!std::strncmp(string.data(), NullCharSet::toStdString().data(),
                       NullCharSet::toStdString().size())) {
        char_consumed =  NullCharSet::toStdString().size();
    } else {
        throw NullUnexpectedException(string[0], getEndPos());
    }

    getEndPos().setColumn(getEndPos().getColumn() + char_consumed - 1);
    return char_consumed;
}

std::string Null::toStdString() {
    return  NullCharSet::toStdString();
}

std::vector<TextElement> Null::toTextElements(Indent indent) {
    return {TextElement(toStdString(), indent, NULL_F)};
}
