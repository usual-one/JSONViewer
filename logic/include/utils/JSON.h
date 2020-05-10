#ifndef UTILS_JSON_H
#define UTILS_JSON_H

#include <set>

const std::set<char> JSONDT_BEGIN_CHAR = {'"','[', '{', 't', 'f', 'n'};

bool isJSONDTStartedWith(char ch);

bool isJSONIgnored(char ch);

bool isBooleanStartedWith(char ch);

bool isFromJSONNumber(char ch);

bool isEulersNumberChar(char ch);

bool isUnarySignChar(char ch);

#endif // UTILS_JSON_H
