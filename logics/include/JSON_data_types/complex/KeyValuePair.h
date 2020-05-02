#ifndef DATA_TYPES_KEYVALUEPAIR_H
#define DATA_TYPES_KEYVALUEPAIR_H

#include "logics/include/JSON_data_types/simple/SimpleDT.h"
#include "logics/include/JSON_data_types/simple/String.h"

class KeyValuePair {
public:
    String key_;
    JSONDT value_;
};

#endif // DATA_TYPES_KEYVALUEPAIR_H
