#ifndef EXCEPTION_DTARRAYEXCEPTION_H
#define EXCEPTION_DTARRAYEXCEPTION_H

#include "logic/include/json/exception/jsonexception.h"

class ArrayException : public JSONException {
public:
    ArrayException(size_t row = -1, size_t col = -1) :
        JSONException(row, col) {}

    ArrayException(const TextPosition &pos) :
        JSONException(pos) {}

    ArrayException(const std::string &msg, size_t row = -1, size_t col = -1) :
        JSONException (msg, row, col) {}

    ArrayException(const std::string &msg, const TextPosition &pos) :
        JSONException (msg, pos) {}
};

class ArrayBracketException : public ArrayException {
public:
    ArrayBracketException(size_t row = -1, size_t col = -1) :
        ArrayException(row, col) {}

    ArrayBracketException(const TextPosition &pos) :
        ArrayException(pos) {}

    ArrayBracketException(const std::string &msg, size_t row = -1, size_t col = -1) :
        ArrayException(msg, row, col) {}

    ArrayBracketException(const std::string &msg, const TextPosition &pos) :
        ArrayException(msg, pos) {}
};

class ArrayBracketBeginException : public ArrayBracketException {
public:
    ArrayBracketBeginException(size_t row = -1, size_t col = -1) :
        ArrayBracketException(row, col) {}

    ArrayBracketBeginException(const TextPosition &pos) :
        ArrayBracketException(pos) {}

    ArrayBracketBeginException(const std::string &msg, size_t row = -1, size_t col = -1) :
        ArrayBracketException(msg, row, col) {}

    ArrayBracketBeginException(const std::string &msg, const TextPosition &pos) :
        ArrayBracketException(msg, pos) {}
};

class ArrayBracketEndException : public ArrayBracketException {
public:
    ArrayBracketEndException(size_t row = -1, size_t col = -1) :
        ArrayBracketException(row, col) {}

    ArrayBracketEndException(const TextPosition &pos) :
        ArrayBracketException(pos) {}

    ArrayBracketEndException(const std::string &msg, size_t row = -1, size_t col = -1) :
        ArrayBracketException(msg, row, col) {}

    ArrayBracketEndException(const std::string &msg, const TextPosition &pos) :
        ArrayBracketException(msg, pos) {}
};

class ArrayUnexpectedException : public ArrayException {
public:
    ArrayUnexpectedException(size_t row = -1, size_t col = -1) :
        ArrayException(row, col) {}

    ArrayUnexpectedException(const TextPosition &pos) :
        ArrayException(pos) {}

    ArrayUnexpectedException(char character, size_t row = -1, size_t col = -1) :
        ArrayException(std::string("unexpected character: ").append(1, character), row, col) {}

    ArrayUnexpectedException(char character, const TextPosition &pos) :
        ArrayException(std::string("unexpected character: ").append(1, character), pos) {}
};

#endif // EXCEPTION_DTARRAYEXCEPTION_H
