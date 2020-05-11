#include "logic/include/exception/FileException.h"

FileException::FileException() {
    msg_ = "";
}

FileException::FileException(const std::string &msg) {
    msg_ = msg;
}

const char *FileException::what() const noexcept {
    return msg_.data();
}
