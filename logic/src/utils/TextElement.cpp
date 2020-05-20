#include "logic/include/utils/TextElement.h"

TextElement::TextElement(const std::string &text, Indent indent , CharFormatName format) {
    text_ = text;
    format_ = format;
    indent_ = indent;
}

std::string &TextElement::getText() {
    return text_;
}

CharFormatName TextElement::getFormat() {
    return format_;
}

std::string &TextElement::getIndent() {
    return indent_.own_;
}
