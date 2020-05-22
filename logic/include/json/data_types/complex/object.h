#ifndef DATA_TYPES_OBJECT_H
#define DATA_TYPES_OBJECT_H

#include "logic/include/json/data_types/complex/complexdt.h"

#include <vector>

class Object : public ComplexDT {
public:
    size_t fromStdString(const std::string &string) final;

    std::string toStdString() final;

    std::vector<TextElement> toTextElements(Indent indent) final;
};

#endif // DATA_TYPES_OBJECT_H
