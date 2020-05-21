#ifndef DATA_TYPES_STRING_H
#define DATA_TYPES_STRING_H

#include "logic/include/json/data_types/simple/simpledt.h"

#include <string>

class String : public SimpleDT {
public:
    size_t fromStdString(const std::string &string) final;

    std::string toStdString() final;

    std::vector<TextElement> toTextElements(Indent indent) final;

private:
    std::string instance_;
};

#endif // DATA_TYPES_STRING_H
