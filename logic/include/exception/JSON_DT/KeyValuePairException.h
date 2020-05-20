#ifndef EXCEPTION_DTKEYVALUEPAIR_H
#define EXCEPTION_DTKEYVALUEPAIR_H

#include "logic/include/exception/JSON_DT/ObjectException.h"

class KeyValuePairException : public ObjectException {
public:
    KeyValuePairException(size_t row = -1, size_t col = -1) :
        ObjectException(row, col) {}

    KeyValuePairException(const TextPosition &pos) :
        ObjectException(pos) {}

    KeyValuePairException(const std::string &msg, size_t row = -1, size_t col = -1) :
        ObjectException (msg, row, col) {}

    KeyValuePairException(const std::string &msg, const TextPosition &pos) :
        ObjectException (msg, pos) {}
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
