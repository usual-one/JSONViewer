#ifndef DATA_TYPES_STRING_H
#define DATA_TYPES_STRING_H

#include "logics/include/JSON_data_types/simple/SimpleDT.h"

#include <string>

class String : public SimpleDT {
private:
    std::string instance_;
};

#endif // DATA_TYPES_STRING_H
