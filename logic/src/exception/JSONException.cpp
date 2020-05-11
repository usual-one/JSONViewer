#include "logic/include/exception/JSONException.h"


JSONException::JSONException(size_t row, size_t col) {
    msg_ = "";
    setPosition(row, col);
}

JSONException::JSONException(const TextPosition &pos)
{
    msg_ = "";
    setPosition(pos);
}

JSONException::JSONException(const std::string &msg, size_t row, size_t col) {
    msg_ = msg;
    setPosition(row, col);
}

JSONException::JSONException(const std::string &msg, const TextPosition &pos)
{
    msg_ = msg;
    setPosition(pos);
}

const char *JSONException::what() const noexcept {
    return msg_.data();
}

TextPosition &JSONException::getPosition() {
    return pos_;
}

void JSONException::setPosition(size_t row, size_t col)
{
    pos_.setPosition(row, col);
}

void JSONException::setPosition(const TextPosition &pos)
{
    pos_.setPosition(pos);
}
