#ifndef MISTAKE_H
#define MISTAKE_H

#include <string>

#include "logic/include/utils/TextPosition.h"

class TextMistake {
public:
    TextMistake() = delete;

    TextMistake(const std::string &msg, const TextPosition &pos);

    TextPosition getPosition();

    void setMessage(const std::string &msg);

    void setPosition(const TextPosition &pos);

    std::string what();

private:
    std::string msg_;

    TextPosition pos_;
};

#endif // MISTAKE_H
