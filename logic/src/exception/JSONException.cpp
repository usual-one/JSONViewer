#include "logic/include/exception/JSONException.h"


JSONException::JSONException(size_t row, size_t col) {
    msg_ = "JSONException at row " + std::to_string(row) +
            " col " + std::to_string(col);
    setPosition(row, col);
}

JSONException::JSONException(const TextPosition &pos)
{
    msg_ = "JSONException at row " + std::to_string(pos.getRow()) +
            " col " + std::to_string(pos.getColumn());
    setPosition(pos);
}

JSONException::JSONException(const std::string &msg, size_t row, size_t col) {
    msg_ = "JSONException at row " + std::to_string(row) +
            " col " + std::to_string(col) +
            ": " + msg;
    setPosition(row, col);
}

JSONException::JSONException(const std::string &msg, const TextPosition &pos)
{
    msg_ = "JSONException at row " + std::to_string(pos.getRow()) +
            " col " + std::to_string(pos.getColumn()) +
            ": " + msg;
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
