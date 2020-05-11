#ifndef EXCEPTION_DTSTRINGEXCEPTION_H
#define EXCEPTION_DTSTRINGEXCEPTION_H

#include "logic/include/exception/JSONException.h"

class StringException : public JSONException {
public:
    StringException(size_t row = -1, size_t col = -1) :
        JSONException(row, col) {}

    StringException(const TextPosition &pos) :
        JSONException(pos) {}

    StringException(const std::string &msg, size_t row = -1, size_t col = -1) :
        JSONException (msg, row, col) {}

    StringException(const std::string &msg, const TextPosition &pos) :
        JSONException (msg, pos) {}
};

class StringQuotationException : public StringException {
public:
    StringQuotationException(size_t row = -1, size_t col = -1) :
        StringException(row, col) {}

    StringQuotationException(const TextPosition &pos) :
        StringException(pos) {}

    StringQuotationException(const std::string &msg, size_t row = -1, size_t col = -1) :
        StringException(msg, row, col) {}

    StringQuotationException(const std::string &msg, const TextPosition &pos) :
        StringException(msg, pos) {}
};

class StringQuotationBeginException : public StringQuotationException {
public:
    StringQuotationBeginException(size_t row = -1, size_t col = -1) :
        StringQuotationException(row, col) {}

    StringQuotationBeginException(const TextPosition &pos) :
        StringQuotationException(pos) {}

    StringQuotationBeginException(const std::string &msg, size_t row = -1, size_t col = -1) :
        StringQuotationException(msg, row, col) {}

    StringQuotationBeginException(const std::string &msg, const TextPosition &pos) :
        StringQuotationException(msg, pos) {}
};

class StringQuotationEndException : public StringQuotationException {
public:
    StringQuotationEndException(size_t row = -1, size_t col = -1) :
        StringQuotationException(row, col) {}

    StringQuotationEndException(const TextPosition &pos) :
        StringQuotationException(pos) {}

    StringQuotationEndException(const std::string &msg, size_t row = -1, size_t col = -1) :
        StringQuotationException(msg, row, col) {}

    StringQuotationEndException(const std::string &msg, const TextPosition &pos) :
        StringQuotationException(msg, pos) {}
};

#endif // EXCEPTION_DTSTRINGEXCEPTION_H
