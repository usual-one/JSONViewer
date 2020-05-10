#ifndef EXCEPTION_FILEEXCEPTION_H
#define EXCEPTION_FILEEXCEPTION_H

#include <exception>
#include <string>

class FileException : std::exception {
public:
    FileException();

    explicit FileException(const std::string &msg);

    const char *what() const noexcept override;

protected:
    std::string msg_;
};

class FileOpeningException : public FileException {
public:
    FileOpeningException() :
        FileException() {}

    explicit FileOpeningException(const std::string &msg) :
        FileException(msg) {}
};

#endif // EXCEPTION_FILEEXCEPTION_H
