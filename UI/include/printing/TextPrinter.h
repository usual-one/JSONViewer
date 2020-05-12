#ifndef PRINTING_TEXTPRINTER_H
#define PRINTING_TEXTPRINTER_H

#include "logic/include/JSON_data_types/DT_headers.h"
#include "UI/include/printing/TextHighlighter.h"

#include <QPlainTextEdit>

class TextPrinter {
public:
    TextPrinter() = delete;

    TextPrinter(QPlainTextEdit *editor);

    void printHighlightedJSON(const Array &arr);

    void printHighlightedJSON(const QObject &arr);

    void print(const QString &text);

private:
    TextHighlighter highlighter_;
};

#endif // PRINTING_TEXTPRINTER_H
