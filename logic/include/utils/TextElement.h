#ifndef TEXTELEMENT_H
#define TEXTELEMENT_H

#include "UI/include/printing/CharFormatName.h"
#include "UI/include/printing/Indent.h"

#include <string>

class TextElement {
public:
    TextElement(const std::string &text, Indent indent = Indent(), CharFormatName format = DEFAULT_F);

    std::string &getText();

    CharFormatName getFormat();

    std::string &getIndent();

private:
    std::string text_;

    Indent indent_;

    CharFormatName format_;
};

#endif // TEXTELEMENT_H
