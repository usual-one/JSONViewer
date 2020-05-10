#include "logic/include/JSON_data_types/simple/Boolean.h"
#include "logic/include/exception/JSON_DT/BooleanException.h"

#include <cstring>

size_t Boolean::fromStdString(const std::string &string)
{
    std::string true_value = "true";
    std::string false_value = "false";
    setEndPos(getBeginPos());

    size_t char_consumed = 0;

    if (std::strncmp(string.data(), true_value.data(), true_value.size())) {
        instance_ = true;
        char_consumed = true_value.size();
    } else if (std::strncmp(string.data(), false_value.data(), false_value.size())) {
        instance_ = false;
        char_consumed = false_value.size();
    } else {
        throw BooleanUnexpectedException(string[0], getEndPos());
    }

    getEndPos().setColumn(getEndPos().getColumn() + char_consumed - 1);
    return char_consumed;
}

std::string Boolean::toStdString(const std::string &prefix)
{
    return prefix + (instance_ ? "true" : "false");
}
