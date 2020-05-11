#ifndef EXCEPTION_DTOBJECTEXCEPTION_H
#define EXCEPTION_DTOBJECTEXCEPTION_H

#include "logic/include/exception/JSONException.h"

class ObjectException : public JSONException {
public:
    ObjectException(size_t row = -1, size_t col = -1) :
        JSONException(row, col) {}

    ObjectException(const TextPosition &pos) :
        JSONException(pos) {}

    ObjectException(const std::string &msg, size_t row = -1, size_t col = -1) :
        JSONException (msg, row, col) {}

    ObjectException(const std::string &msg, const TextPosition &pos) :
        JSONException (msg, pos) {}
};

class ObjectBracketException : public ObjectException {
public:
    ObjectBracketException(size_t row = -1, size_t col = -1) :
        ObjectException(row, col) {}

    ObjectBracketException(const TextPosition &pos) :
        ObjectException(pos) {}

    ObjectBracketException(const std::string &msg, size_t row = -1, size_t col = -1) :
        ObjectException(msg, row, col) {}

    ObjectBracketException(const std::string &msg, const TextPosition &pos) :
        ObjectException(msg, pos) {}
};

class ObjectBracketBeginException : public ObjectBracketException {
public:
    ObjectBracketBeginException(size_t row = -1, size_t col = -1) :
        ObjectBracketException(row, col) {}

    ObjectBracketBeginException(const TextPosition &pos) :
        ObjectBracketException(pos) {}

    ObjectBracketBeginException(const std::string &msg, size_t row = -1, size_t col = -1) :
        ObjectBracketException(msg, row, col) {}

    ObjectBracketBeginException(const std::string &msg, const TextPosition &pos) :
        ObjectBracketException(msg, pos) {}
};

class ObjectBracketEndException : public ObjectBracketException {
public:
    ObjectBracketEndException(size_t row = -1, size_t col = -1) :
        ObjectBracketException(row, col) {}

    ObjectBracketEndException(const TextPosition &pos) :
        ObjectBracketException(pos) {}

    ObjectBracketEndException(const std::string &msg, size_t row = -1, size_t col = -1) :
        ObjectBracketException(msg, row, col) {}

    ObjectBracketEndException(const std::string &msg, const TextPosition &pos) :
        ObjectBracketException(msg, pos) {}
};

class ObjectUnexpectedException : public ObjectException {
public:
    ObjectUnexpectedException(size_t row = -1, size_t col = -1) :
        ObjectException(row, col) {}

    ObjectUnexpectedException(const TextPosition &pos) :
        ObjectException(pos) {}

    ObjectUnexpectedException(char character, size_t row = -1, size_t col = -1) :
        ObjectException(std::string("unexpected character: ").append(1, character), row, col) {}

    ObjectUnexpectedException(char character, const TextPosition &pos) :
        ObjectException(std::string("unexpected character: ").append(1, character), pos) {}
};

#endif // EXCEPTION_DTOBJECTEXCEPTION_H
