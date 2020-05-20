#ifndef PRINTING_TEXTHIGHLIGHTER_H
#define PRINTING_TEXTHIGHLIGHTER_H

#include "UI/include/printing/CharFormatName.h"
#include "logic/include/utils/TextElement.h"
#include "logic/include/utils/TextPosition.h"

#include <QPlainTextEdit>

class TextHighlighter {
public:
    TextHighlighter();

    TextHighlighter(QPlainTextEdit *editor);

    void clear();

    void print(const QString &text, CharFormatName format_name = DEFAULT_F);

    void printMistake(const QString &text);

    void printKey(const QString &text);

    void printNumber(const QString &text);

    void printString(const QString &text);

    void printBoolean(const QString &text);

    void printNull(const QString &text);

    void printTextElements(const QVector<TextElement> &elements);

    void printMistakeHighlighted(const QString &text, const TextPosition &pos);

    void moveCursor(const QTextCursor::MoveOperation &op);

    void moveCursor(const QTextCursor &cursor);

    void moveCursor(size_t pos);

private:
    void setCharFormat(CharFormatName format_name);

    void appendText(const QString &text);

    QPlainTextEdit *editor_;
};

#endif // PRINTING_TEXTHIGHLIGHTER_H
