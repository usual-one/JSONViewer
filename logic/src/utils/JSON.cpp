#include "logic/include/utils/JSON.h"

#include <cctype>

bool isJSONDTStartedWith(char ch) {
    return isFromJSONNumber(ch) || JSONDT_BEGIN_CHAR.count(ch);
}

bool isJSONIgnored(char ch) {
    if (std::isblank(ch)) {
        return true;
    }
    if (ch == '\n') {
        return true;
    }
    if (ch == '\r') {
        return true;
    }
    return false;
}

bool isBooleanStartedWith(char ch) {
    std::string true_str = "true";
    std::string false_str = "false";
    return ch == true_str[0] || ch == false_str[0];
}

bool isFromJSONNumber(char ch) {
    if (std::isdigit(ch)) {
        return true;
    }
    if (isUnarySignChar(ch)) {
        return true;
    }
    if (ch == '.') {
        return true;
    }
    if (isEulersNumberChar(ch)) {
        return true;
    }
    return false;
}

bool isEulersNumberChar(char ch) {
    return ch == 'e' || ch == 'E';
}

bool isUnarySignChar(char ch) {
    return ch == '+' || ch == '-';
}
