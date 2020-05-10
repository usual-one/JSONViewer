#ifndef EXCEPTION_DTNUMBEREXCEPTION_H
#define EXCEPTION_DTNUMBEREXCEPTION_H

#include "logic/include/exception/JSONException.h"

class NumberException : public JSONException {
public:
    NumberException(size_t row = -1, size_t col = -1) :
        JSONException(row, col) {}

    NumberException(const TextPosition &pos) :
        JSONException(pos) {}

    NumberException(const std::string &msg, size_t row = -1, size_t col = -1) :
        JSONException("NumberException: " + msg, row, col) {}

    NumberException(const std::string &msg, const TextPosition &pos) :
        JSONException("NumberException: " + msg, pos) {}
};

class NumberUnexpectedException : public NumberException {
public:
    NumberUnexpectedException(size_t row = -1, size_t col = -1) :
        NumberException(row, col) {}

    NumberUnexpectedException(const TextPosition &pos) :
        NumberException(pos) {}

    NumberUnexpectedException(char character, size_t row = -1, size_t col = -1) :
        NumberException(std::string("unexpected character: ").append(1, character), row, col) {}

    NumberUnexpectedException(char character, const TextPosition &pos) :
        NumberException(std::string("unexpected character: ").append(1, character), pos) {}
};

class NumberEmptyException : public NumberException {
public:
    NumberEmptyException(size_t row = -1, size_t col = -1) :
        NumberException(row, col) {}

    NumberEmptyException(const TextPosition &pos) :
        NumberException(pos) {}

    NumberEmptyException(const std::string &msg, size_t row = -1, size_t col = -1) :
        NumberException(msg, row, col) {}

    NumberEmptyException(const std::string &msg, const TextPosition &pos) :
        NumberException(msg, pos) {}
};

#endif // EXCEPTION_DTNUMBEREXCEPTION_H
