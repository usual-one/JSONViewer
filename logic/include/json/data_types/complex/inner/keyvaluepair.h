#ifndef DATA_TYPES_KEYVALUEPAIR_H
#define DATA_TYPES_KEYVALUEPAIR_H

#include "logic/include/json/data_types/complex/inner/innerdt.h"
#include "logic/include/json/data_types/simple/string.h"

#include <memory>

class KeyValuePair : public InnerDT {
public:
    KeyValuePair();

    size_t fromStdString(const std::string &string) final;

    std::string toStdString() final;

    std::vector<TextElement> toTextElements(Indent indent) final;

private:
    std::unique_ptr<String> key_;

    std::unique_ptr<JSONDT> value_;
};

#endif // DATA_TYPES_KEYVALUEPAIR_H
