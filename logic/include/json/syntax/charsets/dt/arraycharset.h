#ifndef JSON_ARRAYCHARSET_H
#define JSON_ARRAYCHARSET_H

#include <string>
#include <vector>

#include "logic/include/json/syntax/charsets/charset.h"

class ArrayCharSet : public CharSet {
public:
    static std::vector<std::string> getBorders();

    static void setBorders(const std::vector<std::string> &value);

private:
    static std::vector<std::string> borders_;

};

#endif // JSON_ARRAYCHARSET_H
