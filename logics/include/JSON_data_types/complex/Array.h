#ifndef DATA_TYPES_ARRAY_H
#define DATA_TYPES_ARRAY_H

#include "logics/include/JSON_data_types/JSONDT.h"
#include "logics/include/JSON_data_types/complex/ComplexDT.h"

class Array : public ComplexDT {
private:
    std::vector<JSONDT> instance_;
};

#endif // DATA_TYPES_ARRAY_H
