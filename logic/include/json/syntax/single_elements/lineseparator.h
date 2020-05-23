#ifndef JSON_LINESEPARATOR_H
#define JSON_LINESEPARATOR_H

#include <string>

#include "logic/include/json/syntax/single_elements/singlesyntaxelement.h"

class LineSeparator : public SingleSyntaxElement {
public:
    static std::string toStdString();

    static void setInstance(const std::string &value);

    static bool isEqual(const std::string &other);

    static bool isEqual(char other);

protected:
    static std::string instance_;
};

#endif // JSON_LINESEPARATOR_H
