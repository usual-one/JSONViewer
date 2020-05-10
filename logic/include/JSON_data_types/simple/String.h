#ifndef DATA_TYPES_STRING_H
#define DATA_TYPES_STRING_H

#include "logic/include/JSON_data_types/simple/SimpleDT.h"

#include <string>

class String : public SimpleDT {
public:
    size_t fromStdString(const std::string &string) final;

    std::string toStdString(const std::string &prefix = "") final;

private:
    std::string instance_;
};

#endif // DATA_TYPES_STRING_H
