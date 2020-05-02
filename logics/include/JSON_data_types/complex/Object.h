#ifndef DATA_TYPES_OBJECT_H
#define DATA_TYPES_OBJECT_H

#include "logics/include/JSON_data_types/complex/ComplexDT.h"
#include "logics/include/JSON_data_types/complex/KeyValuePair.h"

#include <vector>

class Object : public ComplexDT {
private:
    std::vector<KeyValuePair> instance_;
};

#endif // DATA_TYPES_OBJECT_H
