#ifndef JSON_NULLCHARSET_H
#define JSON_NULLCHARSET_H

#include <string>

#include "logic/include/json/syntax/charsets/charset.h"

class NullCharSet : public CharSet {
public:
    static std::string toStdString();

    static void setValue(const std::string &value);

private:
    static std::string value_;
};

#endif // JSON_NULLCHARSET_H
