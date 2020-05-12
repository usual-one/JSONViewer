#ifndef PRINTING_TEXTHIGHLIGHTER_H
#define PRINTING_TEXTHIGHLIGHTER_H

#include <QPlainTextEdit>

enum CharFormatName {
    DEFAULT_F,
    MISTAKE_F,
    KEY_F,
    NUMBER_F,
    STRING_F,
    BOOLEAN_F,
    NULL_F
};

class TextHighlighter {
public:
    TextHighlighter() = delete;

    TextHighlighter(QPlainTextEdit *editor);

    void clear();

    void print(const QString &text);

    void printMistake(const QString &text);

    void printKey(const QString &text);

    void printNumber(const QString &text);

    void printString(const QString &text);

    void printBoolean(const QString &text);

    void printNull(const QString &text);

    void moveCursor(const QTextCursor::MoveOperation &op);

private:
    void setCharFormat(CharFormatName format_name);

    void appendText(const QString &text);

    QPlainTextEdit *editor_;
};

#endif // PRINTING_TEXTHIGHLIGHTER_H
