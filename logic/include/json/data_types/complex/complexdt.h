#ifndef DATA_TYPES_COMPLEXDT_H
#define DATA_TYPES_COMPLEXDT_H

#include "logic/include/json/data_types/jsondt.h"

#include <vector>
#include <memory>

class ComplexDT : public JSONDT {
protected:
    std::vector<std::unique_ptr<JSONDT>> instance_;
};

#endif // DATA_TYPES_COMPLEXDT_H
