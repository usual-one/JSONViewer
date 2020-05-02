#ifndef EXCEPTION_JSONEXCEPTION_H
#define EXCEPTION_JSONEXCEPTION_H

#include <exception>
#include <string>

class JSONException : public std::exception {
public:
    JSONException();

    explicit JSONException(const std::string &msg);

    const char *what() const noexcept override;

protected:
    std::string msg_;
};

#endif // EXCEPTION_JSONEXCEPTION_H
