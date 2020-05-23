#ifndef JSON_STRINGCHARSET_H
#define JSON_STRINGCHARSET_H

#include <string>

#include "logic/include/json/syntax/charsets/charset.h"

class StringCharSet : public CharSet {
public:
    static std::string getBorder();

    static void setBorder(const std::string &value);

private:
    static std::string border_;

};

#endif // JSON_STRINGCHARSET_H
