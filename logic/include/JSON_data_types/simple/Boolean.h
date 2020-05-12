#ifndef DATA_TYPES_BOOLEAN_H
#define DATA_TYPES_BOOLEAN_H

#include "logic/include/JSON_data_types/simple/SimpleDT.h"

class Boolean : public SimpleDT {
public:
    size_t fromStdString(const std::string &string) final;

    std::string toStdString() final;

    void printOnWidget(TextHighlighter &highlighter, const std::string &prefix = "") final;

private:
    bool instance_;
};

#endif // DATA_TYPES_BOOLEAN_H
