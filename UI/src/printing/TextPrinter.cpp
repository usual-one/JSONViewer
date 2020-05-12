#include "UI/include/printing/TextPrinter.h"

TextPrinter::TextPrinter(QPlainTextEdit *editor) : highlighter_(editor) {}

void TextPrinter::printHighlightedJSON(const Array &arr) {

}

void TextPrinter::print(const QString &text) {
    highlighter_.print(text);
}


