#include <cstring>
#include <set>

#include "logic/include/json/jsonparser.h"
#include "logic/include/json/syntax.h"
#include "logic/include/json/data_types/dt_headers.h"
#include "logic/include/json/exception/jsonexception.h"

std::shared_ptr<JSONDT> JSONParser::parse(const std::string &json_str) {
    if (!json_str.size()) {
        return nullptr;
    }
    if (startsLike(json_str, ARRAY_DT)) {
        auto json = std::make_shared<Array>();
        json->fromStdString(json_str);
        return json;
    }
    if (startsLike(json_str, OBJECT_DT)) {
        auto json = std::make_shared<Object>();
        json->fromStdString(json_str);
        return json;
    }
    throw JSONException("unexpected character");
}

std::unique_ptr<JSONDT> JSONParser::createFromStartStr(const std::string &json) {
    if (startsLike(json, ARRAY_DT)) {
        return std::make_unique<Array>();
    } else if (startsLike(json, OBJECT_DT)) {
        return std::make_unique<Object>();
    } else if (startsLike(json, STRING_DT)) {
        return std::make_unique<String>();
    } else if (startsLike(json, BOOLEAN_DT)) {
        return std::make_unique<Boolean>();
    } else if (startsLike(json, NULL_DT)) {
        return std::make_unique<Null>();
    } else if (startsLike(json, NUMBER_DT)) {
        return std::make_unique<Number>();
    }
    throw JSONException("nothing to create");
}

bool JSONParser::startsLike(const std::string &json, DTName format) {
    if (format == ARRAY_DT) {
        return json.size() >= ARRAY_BORDER_BEGIN.size() &&
                !json.compare(0, ARRAY_BORDER_BEGIN.size(), ARRAY_BORDER_BEGIN);
    } else if (format == OBJECT_DT) {
        return json.size() >= OBJECT_BORDER_BEGIN.size() &&
                !json.compare(0, OBJECT_BORDER_BEGIN.size(), OBJECT_BORDER_BEGIN);
    } else if (format == BOOLEAN_DT) {
        return json.size() && (json[0] == TRUE_VALUE[0] || json[0] == FALSE_VALUE[0]);
    } else if (format == NULL_DT) {
        return json.size() && (json[0] == NULL_VALUE[0]);
    } else if (format == NUMBER_DT) {
        return json.size() && isFromNumber(json[0]);
    } else if (format == STRING_DT) {
        return json.size() >= STRING_BORDER.size() &&
                !json.compare(0, STRING_BORDER.size(), STRING_BORDER);
    }
    return false;
}

bool JSONParser::endsLike(const std::string &json, DTName format){
    if (format == ARRAY_DT) {
        return json.size() >= ARRAY_BORDER_END.size() &&
                !json.compare(json.size() - ARRAY_BORDER_END.size(), json.size(), ARRAY_BORDER_END);
    } else if (format == OBJECT_DT) {
        return json.size() >= OBJECT_BORDER_END.size() &&
                !json.compare(json.size() - OBJECT_BORDER_END.size(), json.size(), OBJECT_BORDER_END);
    } else if (format == BOOLEAN_DT) {
        return json.size() &&
                (json[json.size() - 1] == TRUE_VALUE[TRUE_VALUE.size() - 1] ||
                json[json.size() - 1] == FALSE_VALUE[FALSE_VALUE.size() - 1]);
    } else if (format == NULL_DT) {
        return json.size() && (json[json.size() - 1] == NULL_VALUE[NULL_VALUE.size() - 1]);
    } else if (format == NUMBER_DT) {
        return json.size() && isFromNumber(json[json.size() - 1]);
    } else if (format == STRING_DT) {
        return json.size() >= STRING_BORDER.size() &&
                !json.compare(json.size() - STRING_BORDER.size(), json.size(), STRING_BORDER);
    }
    return false;
}

bool JSONParser::canJSONStartWith(char ch) {
    return ch == ARRAY_BORDER_BEGIN[0] ||
            ch == OBJECT_BORDER_BEGIN[0] ||
            ch == TRUE_VALUE[0] ||
            ch == FALSE_VALUE[0] ||
            ch == NULL_VALUE[0] ||
            ch == STRING_BORDER[0] ||
            isFromNumber(ch);
}

bool JSONParser::isValueSeparator(const std::string &json) {
    return json.size() >= DEFAULT_VALUE_SEPARATOR.size() &&
            !json.compare(0, DEFAULT_VALUE_SEPARATOR.size(), DEFAULT_VALUE_SEPARATOR);
}

bool JSONParser::isLineSeparator(const std::string &json) {
    return json.size() >= DEFAULT_LINE_SEPARATOR.size() &&
            !json.compare(0, DEFAULT_LINE_SEPARATOR.size(), DEFAULT_LINE_SEPARATOR);
}

bool JSONParser::isKeyValuePairSeparator(const std::string &json) {
    return json.size() >= KEY_VALUE_PAIR_SEPARATOR.size() &&
            !json.compare(0, KEY_VALUE_PAIR_SEPARATOR.size(), KEY_VALUE_PAIR_SEPARATOR);
}

bool JSONParser::isFromNumber(char ch) {


    if (std::isdigit(ch)) {
        return true;
    }
    if (isEulersNumber(ch)) {
        return true;
    }
    if (ch == '.') {
        return true;
    }
    if (isUnarySign(ch)) {
        return true;
    }
    return false;
}

bool JSONParser::isEulersNumber(char ch) {
    std::set<char> eulers_number = {'e', 'E'};
    return eulers_number.count(ch);
}

bool JSONParser::isUnarySign(char ch) {
    std::set<char> number_signs = {'-', '+'};
    return  number_signs.count(ch);
}

bool JSONParser::isJSONIgnored(char ch) {
    if (std::isblank(ch)) {
        return true;
    }
    if (isLineSeparator(std::string(1, ch))) {
        return true;
    }
    if (ch == '\r') {
        return true;
    }
    return false;
}
