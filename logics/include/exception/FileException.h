#ifndef EXCEPTION_FILEEXCEPTION_H
#define EXCEPTION_FILEEXCEPTION_H

#include "logics/include/exception/JSONException.h"

class FileException : public JSONException {
public:
    FileException() :
        JSONException() {}

    explicit FileException(const std::string &msg) :
        JSONException("FileException: " + msg) {}
};

class FileOpeningException : public FileException {
public:
    FileOpeningException() :
        FileException() {}

    explicit FileOpeningException(const std::string &msg) :
        FileException(msg) {}
};

#endif // EXCEPTION_FILEEXCEPTION_H
