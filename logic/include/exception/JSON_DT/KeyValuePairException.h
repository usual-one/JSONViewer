#ifndef EXCEPTION_DTKEYVALUEPAIR_H
#define EXCEPTION_DTKEYVALUEPAIR_H

#include "logic/include/exception/JSONException.h"

class KeyValuePairException : public JSONException {
public:
    KeyValuePairException(size_t row = -1, size_t col = -1) :
        JSONException(row, col) {}

    KeyValuePairException(const TextPosition &pos) :
        JSONException(pos) {}

    KeyValuePairException(const std::string &msg, size_t row = -1, size_t col = -1) :
        JSONException (msg, row, col) {}

    KeyValuePairException(const std::string &msg, const TextPosition &pos) :
        JSONException (msg, pos) {}
};

class KeyValuePairNoValueException : public KeyValuePairException {
public:
    KeyValuePairNoValueException(size_t row = -1, size_t col = -1) :
        KeyValuePairException(row, col) {}

    KeyValuePairNoValueException(const TextPosition &pos) :
        KeyValuePairException(pos) {}

    KeyValuePairNoValueException(const std::string &msg, size_t row = -1, size_t col = -1) :
        KeyValuePairException (msg, row, col) {}

    KeyValuePairNoValueException(const std::string &msg, const TextPosition &pos) :
        KeyValuePairException (msg, pos) {}
};

class KeyValuePairNoSeparatorException : public KeyValuePairException {
public:
    KeyValuePairNoSeparatorException(size_t row = -1, size_t col = -1) :
        KeyValuePairException(row, col) {}

    KeyValuePairNoSeparatorException(const TextPosition &pos) :
        KeyValuePairException(pos) {}

    KeyValuePairNoSeparatorException(const std::string &msg, size_t row = -1, size_t col = -1) :
        KeyValuePairException(msg, row, col) {}

    KeyValuePairNoSeparatorException(const std::string &msg, const TextPosition &pos) :
        KeyValuePairException(msg, pos) {}
};

class KeyValuePairUnexpectedException : public KeyValuePairException {
public:
    KeyValuePairUnexpectedException(size_t row = -1, size_t col = -1) :
        KeyValuePairException(row, col) {}

    KeyValuePairUnexpectedException(const TextPosition &pos) :
        KeyValuePairException(pos) {}

    KeyValuePairUnexpectedException(char character, size_t row = -1, size_t col = -1) :
        KeyValuePairException(std::string("unexpected character: ").append(1, character), row, col) {}

    KeyValuePairUnexpectedException(char character, const TextPosition &pos) :
        KeyValuePairException(std::string("unexpected character: ").append(1, character), pos) {}
};


#endif // EXCEPTION_DTKEYVALUEPAIR_H
