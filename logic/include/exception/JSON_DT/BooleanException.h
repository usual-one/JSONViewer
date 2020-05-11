#ifndef EXCEPTION_DTBOOLEANEXCEPTION_H
#define EXCEPTION_DTBOOLEANEXCEPTION_H

#include "logic/include/exception/JSONException.h"

class BooleanException : public JSONException {
public:
    BooleanException(size_t row = -1, size_t col = -1) :
        JSONException(row, col) {}

    BooleanException(const TextPosition &pos) :
        JSONException(pos) {}

    BooleanException(const std::string &msg, size_t row = -1, size_t col = -1) :
        JSONException(msg, row, col) {}

    BooleanException(const std::string &msg, const TextPosition &pos) :
        JSONException(msg, pos) {}
};

class BooleanUnexpectedException : public BooleanException {
public:
    BooleanUnexpectedException(size_t row = -1, size_t col = -1) :
        BooleanException(row, col) {}

    BooleanUnexpectedException(const TextPosition &pos) :
        BooleanException(pos) {}

    BooleanUnexpectedException(char character, size_t row = -1, size_t col = -1) :
        BooleanException(std::string("unexpected character: ").append(1, character), row, col) {}

    BooleanUnexpectedException(char character, const TextPosition &pos) :
        BooleanException(std::string("unexpected character: ").append(1, character), pos) {}
};

#endif // EXCEPTION_DTBOOLEANEXCEPTION_H
