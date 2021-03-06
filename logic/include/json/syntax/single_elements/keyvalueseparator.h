#ifndef JSON_KEYVALUESEPARATOR_H
#define JSON_KEYVALUESEPARATOR_H

#include <string>

#include "logic/include/json/syntax/single_elements/singlesyntaxelement.h"

class KeyValueSeparator : public SingleSyntaxElement {
public:
    static std::string toStdString();

    static void setInstance(const std::string &value);

    static bool isEqual(const std::string &other);

    static bool isEqual(char other);

protected:
    static std::string instance_;
};

#endif // JSON_KEYVALUESEPARATOR_H
