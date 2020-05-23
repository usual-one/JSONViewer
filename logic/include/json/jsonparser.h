#ifndef JSON_JSONPARSER_H
#define JSON_JSONPARSER_H

#include <memory>
#include <string>

#include "logic/include/json/data_types/jsondt.h"

class JSONParser {
public:
    std::shared_ptr<JSONDT> parse(const std::string &json);

};

#endif // JSON_JSONPARSER_H
