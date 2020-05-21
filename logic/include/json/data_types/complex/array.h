#ifndef DATA_TYPES_ARRAY_H
#define DATA_TYPES_ARRAY_H

#include "logic/include/json/data_types/jsondt.h"
#include "logic/include/json/data_types/complex/complexdt.h"

#include <memory>

class Array : public ComplexDT {
public:
    size_t fromStdString(const std::string &string) final;

    std::string toStdString() final;

    std::vector<TextElement> toTextElements(Indent indent) final;

private:
    std::vector<std::unique_ptr<JSONDT>> instance_;
};

#endif // DATA_TYPES_ARRAY_H
