#include "logic/include/textmistake.h"
#include "config.h"

TextMistake::TextMistake(const std::string &msg, const TextPosition &pos) {
    msg_ = msg;
    pos_ = pos;
}

TextPosition TextMistake::getPosition() {
    return pos_;
}

void TextMistake::setMessage(const std::string &msg) {
    msg_ = msg;
}

void TextMistake::setPosition(const TextPosition &pos) {
    pos_ = pos;
}

std::string TextMistake::what() {
    std::string what_str = msg_;
    if (msg_ == NO_MISTAKES_MESSAGE) {
        return what_str;
    }
    what_str += " (line " + std::to_string(pos_.getRow() + 1) + ",";
    what_str += " character " + std::to_string(pos_.getColumn() + 1) + ")";
    return what_str;
}
