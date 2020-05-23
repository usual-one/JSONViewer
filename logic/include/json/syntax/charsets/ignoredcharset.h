#ifndef JSON_IGNOREDCHARSET_H
#define JSON_IGNOREDCHARSET_H

#include "logic/include/json/syntax/syntaxelement.h"

class IgnoredCharSet : public SyntaxElement {
public:
    static bool isInside(char other);

private:
};

#endif // JSON_IGNOREDCHARSET_H
