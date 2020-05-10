#ifndef DATA_TYPES_NUMBER_H
#define DATA_TYPES_NUMBER_H

#include "logic/include/JSON_data_types/simple/SimpleDT.h"

class Number : public SimpleDT {
public:
    size_t fromStdString(const std::string &string) final;

    std::string toStdString(const std::string &prefix = "") final;

private:
    double instance_;
};

#endif // DATA_TYPES_NUMBER_H
