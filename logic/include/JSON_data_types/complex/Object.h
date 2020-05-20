#ifndef DATA_TYPES_OBJECT_H
#define DATA_TYPES_OBJECT_H

#include "logic/include/JSON_data_types/complex/ComplexDT.h"
#include "logic/include/JSON_data_types/complex/KeyValuePair.h"

#include <vector>

class Object : public ComplexDT {
public:
    size_t fromStdString(const std::string &string) final;

    std::string toStdString() final;

    std::vector<TextElement> toTextElements(Indent indent) final;

private:
    std::vector<std::unique_ptr<KeyValuePair>> instance_;
};

#endif // DATA_TYPES_OBJECT_H
