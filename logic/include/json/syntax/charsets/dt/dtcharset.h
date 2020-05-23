#ifndef JSON_JSONDTBORDERS_H
#define JSON_JSONDTBORDERS_H

#include <memory>
#include <string>

#include "logic/include/json/syntax/charsets/charset.h"
#include "logic/include/json/data_types/jsondt.h"
#include "logic/include/json/data_types/dtname.h"

class DTCharSet : public CharSet {
public:
    static bool startsLike(const std::string &other, DTName dt);

    static bool endsLike(const std::string &other, DTName dt);

    static bool canBeStart(char other);

    static std::unique_ptr<JSONDT> createDTFromStart(const std::string &other);

};

#endif // JSON_JSONDTBORDERS_H
