#ifndef JSON_OBJECTCHARSET_H
#define JSON_OBJECTCHARSET_H

#include <string>
#include <vector>

#include "logic/include/json/syntax/charsets/charset.h"

class ObjectCharSet : public CharSet {
public:
    static std::vector<std::string> getBorders();

    static void setBorders(const std::vector<std::string> &value);

private:
    static std::vector<std::string> borders_;

};

#endif // JSON_OBJECTCHARSET_H
