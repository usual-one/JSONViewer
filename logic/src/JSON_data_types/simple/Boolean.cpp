#include "logic/include/JSON_data_types/simple/Boolean.h"
#include "logic/include/exception/JSON_DT/BooleanException.h"
#include "logic/include/syntax_config.h"

#include <cstring>

size_t Boolean::fromStdString(const std::string &string) {
    setEndPos(getBeginPos());

    size_t char_consumed = 0;

    if (!std::strncmp(string.data(), TRUE_VALUE.data(), TRUE_VALUE.size())) {
        instance_ = true;
        char_consumed = TRUE_VALUE.size();
    } else if (!std::strncmp(string.data(), FALSE_VALUE.data(), FALSE_VALUE.size())) {
        instance_ = false;
        char_consumed = FALSE_VALUE.size();
    } else {
        throw BooleanUnexpectedException(string[0], getEndPos());
    }

    getEndPos().setColumn(getEndPos().getColumn() + char_consumed - 1);
    return char_consumed;
}

std::string Boolean::toStdString() {
    return instance_ ? TRUE_VALUE : FALSE_VALUE;
}

std::vector<TextElement> Boolean::toTextElements(Indent indent) {
    return {TextElement(toStdString(), indent, BOOLEAN_F)};
}
