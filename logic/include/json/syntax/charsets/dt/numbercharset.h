#ifndef JSON_NUMBERCHARSET_H
#define JSON_NUMBERCHARSET_H

#include <set>

#include "logic/include/json/syntax/charsets/charset.h"

class NumberCharSet : public CharSet {
public:
    NumberCharSet();

    bool isEulersNumberFound();

    bool isDecimalSeparatorFound();

    void setEulersNumberFound(bool value);

    void setDecimalSeparatorFound(bool value);

    static bool isInside(char other);

    static bool isDigit(char other);

    static bool isUnarySign(char other);

    static bool isEulersNumber(char other);

    static bool isDecimalSeparator(char other);

private:
    bool eulers_number_found_;

    bool decimal_separator_found_;

    static std::set<std::string> unary_signs_;

    static std::set<std::string> eulers_number_;

    static std::string decimal_separator_;

};

#endif // JSON_NUMBERCHARSET_H
