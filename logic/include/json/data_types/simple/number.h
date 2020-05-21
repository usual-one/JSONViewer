#ifndef DATA_TYPES_NUMBER_H
#define DATA_TYPES_NUMBER_H

#include "logic/include/json/data_types/simple/simpledt.h"

class Number : public SimpleDT {
public:
    size_t fromStdString(const std::string &string) final;

    std::string toStdString() final;

    std::vector<TextElement> toTextElements(Indent indent) final;

//    void printOnWidget(TextHighlighter &highlighter, const std::string &prefix = "") final;

private:
    double instance_;

    std::string in_text_;
};

#endif // DATA_TYPES_NUMBER_H
