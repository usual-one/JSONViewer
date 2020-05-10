#ifndef DATA_TYPES_KEYVALUEPAIR_H
#define DATA_TYPES_KEYVALUEPAIR_H

#include "logic/include/JSON_data_types/complex/ComplexDT.h"
#include "logic/include/JSON_data_types/simple/SimpleDT.h"
#include "logic/include/JSON_data_types/simple/String.h"

#include <memory>

class KeyValuePair : public ComplexDT {
public:
    KeyValuePair();

    size_t fromStdString(const std::string &string) final;

    std::string toStdString(const std::string &prefix = "") final;

private:
    std::unique_ptr<String> key_;

    std::unique_ptr<JSONDT> value_;
};

#endif // DATA_TYPES_KEYVALUEPAIR_H
