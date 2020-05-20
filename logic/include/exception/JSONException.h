#ifndef EXCEPTION_JSONEXCEPTION_H
#define EXCEPTION_JSONEXCEPTION_H

#include "logic/include/utils/TextPosition.h"

#include <exception>
#include <string>

class JSONException : public std::exception {
public:
    JSONException(size_t row = 0, size_t col = 0);

    JSONException(const TextPosition &pos);

    explicit JSONException(const std::string &msg, size_t row = 0, size_t col = 0);

    explicit JSONException(const std::string &msg, const TextPosition &pos);

    const char *what() const noexcept override;

    TextPosition &getPosition();

protected:
    std::string msg_;

    TextPosition pos_;

private:
    void setPosition(size_t row, size_t col);

    void setPosition(const TextPosition &pos);
};

#endif // EXCEPTION_JSONEXCEPTION_H
