#include "logic/include/exception/FileException.h"

FileException::FileException() {
    msg_ = "FileException";
}

FileException::FileException(const std::string &msg) {
    msg_ = "FileException: " + msg;
}

const char *FileException::what() const noexcept {
    return msg_.data();
}
