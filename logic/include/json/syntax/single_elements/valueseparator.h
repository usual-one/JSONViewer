#ifndef JSON_VALUESEPARATOR_H
#define JSON_VALUESEPARATOR_H

#include <string>

#include "logic/include/json/syntax/single_elements/singlesyntaxelement.h"

class ValueSeparator : public SingleSyntaxElement {
public:
    ValueSeparator();

    bool isNeeded();

    void setNeeded(bool value);

    static std::string toStdString();

    static void setInstance(const std::string &value);

    static bool isEqual(const std::string &other);

    static bool isEqual(char other);

private:
    bool needed_;

    static std::string instance_;

};

#endif // JSON_VALUESEPARATOR_H
