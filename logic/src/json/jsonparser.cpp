#include "logic/include/json/jsonparser.h"
#include "logic/include/json/data_types/dt_headers.h"
#include "logic/include/json/exception/jsonexception.h"
#include "logic/include/json/syntax/charsets/dt/dtcharset.h"

std::shared_ptr<JSONDT> JSONParser::parse(const std::string &json_str) {
    if (!json_str.size()) {
        return nullptr;
    }
    if (DTCharSet::startsLike(json_str, ARRAY_DT)) {
        auto json = std::make_shared<Array>();
        json->fromStdString(json_str);
        return json;
    }
    if (DTCharSet::startsLike(json_str, OBJECT_DT)) {
        auto json = std::make_shared<Object>();
        json->fromStdString(json_str);
        return json;
    }
    throw JSONException("unexpected character");
}
