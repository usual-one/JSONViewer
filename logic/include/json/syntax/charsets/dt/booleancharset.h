#ifndef JSON_BOOLEANCHARSET_H
#define JSON_BOOLEANCHARSET_H

#include <string>

#include "logic/include/json/syntax/charsets/charset.h"

class BooleanCharSet : public CharSet {
public:
    static std::string getTrue();

    static std::string getFalse();

    static std::string toStdString(bool value);

    static void setTrueValue(const std::string &value);

    static void setFalseValue(const std::string &value);

private:
    static std::string true_value_;

    static std::string false_value_;
};

#endif // JSON_BOOLEANCHARSET_H
