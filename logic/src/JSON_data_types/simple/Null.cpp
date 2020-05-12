#include "logic/include/JSON_data_types/simple/Null.h"
#include "logic/include/exception/JSON_DT/NullException.h"

#include <cstring>

size_t Null::fromStdString(const std::string &string) {
    setEndPos(getBeginPos());
    std::string null_value = "null";
    size_t char_consumed = 0;

    if (!std::strncmp(string.data(), null_value.data(), null_value.size())) {
        char_consumed = null_value.size();
    } else {
        throw NullUnexpectedException(string[0], getEndPos());
    }

    getEndPos().setColumn(getEndPos().getColumn() + char_consumed - 1);
    return char_consumed;
}

std::string Null::toStdString() {
    return "null";
}

void Null::printOnWidget(TextHighlighter &highlighter, const std::string &prefix) {
    highlighter.printNull((prefix + toStdString()).data());
}
