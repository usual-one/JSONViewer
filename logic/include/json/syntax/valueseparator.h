#ifndef JSON_VALUESEPARATOR_H
#define JSON_VALUESEPARATOR_H

#include <string>

#include "logic/include/json/syntax/syntaxelement.h"

class ValueSeparator {
public:
    ValueSeparator();

    std::string toStdString();

    bool isNeeded();

    void setNeeded(bool value);

    void setInstance(const std::string &value);

private:
    std::string instance_;

    bool needed_;
};

#endif // JSON_VALUESEPARATOR_H
