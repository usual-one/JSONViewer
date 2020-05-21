#ifndef JSON_JSONPARSER_H
#define JSON_JSONPARSER_H

#include <memory>
#include <string>

#include "logic/include/json/data_types/jsondt.h"
#include "logic/include/json/data_types/dtname.h"

class JSONParser {
public:
    std::shared_ptr<JSONDT> parse(const std::string &json);

    std::unique_ptr<JSONDT> createFromStartStr(const std::string &json);

    bool startsLike(const std::string &json, DTName format);

    bool endsLike(const std::string &json, DTName format);

    bool canJSONStartWith(char ch);

    bool isValueSeparator(const std::string &json);

    bool isLineSeparator(const std::string &json);

    bool isKeyValuePairSeparator(const std::string &json);

    bool isFromNumber(char ch);

    bool isEulersNumber(char ch);

    bool isUnarySign(char ch);

    bool isJSONIgnored(char ch);

};

#endif // JSON_JSONPARSER_H
