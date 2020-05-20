#ifndef DATA_TYPES_ARRAY_H
#define DATA_TYPES_ARRAY_H

#include "logic/include/JSON_data_types/JSONDT.h"
#include "logic/include/JSON_data_types/complex/ComplexDT.h"

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
