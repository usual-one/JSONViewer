#ifndef EXCEPTION_DTNULLEXCEPTION_H
#define EXCEPTION_DTNULLEXCEPTION_H

#include "logic/include/exception/JSONException.h"

class NullException : public JSONException {
public:
    NullException(size_t row = -1, size_t col = -1) :
        JSONException(row, col) {}

    NullException(const TextPosition &pos) :
        JSONException(pos) {}

    NullException(const std::string &msg, size_t row = -1, size_t col = -1) :
        JSONException(msg, row, col) {}

    NullException(const std::string &msg, const TextPosition &pos) :
        JSONException(msg, pos) {}
};

class NullUnexpectedException : public NullException {
public:
    NullUnexpectedException(size_t row = -1, size_t col = -1) :
        NullException(row, col) {}

    NullUnexpectedException(const TextPosition &pos) :
        NullException(pos) {}

    NullUnexpectedException(char character, size_t row = -1, size_t col = -1) :
        NullException(std::string("unexpected character: ").append(1, character), row, col) {}

    NullUnexpectedException(char character, const TextPosition &pos) :
        NullException(std::string("unexpected character: ").append(1, character), pos) {}
};

#endif // EXCEPTION_DTNULLEXCEPTION_H
