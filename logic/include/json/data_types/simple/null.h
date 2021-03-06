#ifndef DATA_TYPES_NULL_H
#define DATA_TYPES_NULL_H

#include "logic/include/json/data_types/simple/simpledt.h"

class Null : public SimpleDT {
public:
    size_t fromStdString(const std::string &string) final;

    std::string toStdString() final;

    std::vector<TextElement> toTextElements(Indent indent) final;

//    void printOnWidget(TextHighlighter &highlighter, const std::string &prefix = "") final;
};

#endif // DATA_TYPES_NULL_H
