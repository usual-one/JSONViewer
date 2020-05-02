#include "logics/include/exception/JSONException.h"


JSONException::JSONException()
{
    msg_ = "JSONException";
}

JSONException::JSONException(const std::string &msg)
{
    msg_ = "JSONException: " + msg;
}

const char *JSONException::what() const noexcept
{
    return msg_.data();
}
