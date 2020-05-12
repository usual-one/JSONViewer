#include "UI/include/printing/TextHighlighter.h"
#include "UI/include/config.h"
#include EDITOR_COLOR_SCHEME


TextHighlighter::TextHighlighter(QPlainTextEdit *editor) {
    editor_ = editor;
}

void TextHighlighter::clear() {
    editor_->clear();
    editor_->moveCursor(QTextCursor::Start);
}

void TextHighlighter::print(const QString &text) {
    setCharFormat(DEFAULT_F);
    appendText(text);
}

void TextHighlighter::printMistake(const QString &text) {
    setCharFormat(MISTAKE_F);
    appendText(text);
}

void TextHighlighter::printKey(const QString &text) {
    setCharFormat(KEY_F);
    appendText(text);
}

void TextHighlighter::printNumber(const QString &text) {
    setCharFormat(NUMBER_F);
    appendText(text);
}

void TextHighlighter::printString(const QString &text) {
    setCharFormat(STRING_F);
    appendText(text);
}

void TextHighlighter::printBoolean(const QString &text) {
    setCharFormat(BOOLEAN_F);
    appendText(text);
}

void TextHighlighter::printNull(const QString &text) {
    setCharFormat(NULL_F);
    appendText(text);
}

void TextHighlighter::moveCursor(const QTextCursor::MoveOperation &op) {
    QTextCharFormat format = editor_->currentCharFormat();
    editor_->moveCursor(op);
    editor_->setCurrentCharFormat(format);
}

void TextHighlighter::setCharFormat(CharFormatName format_name) {
    QTextCharFormat format = editor_->currentCharFormat();

    if (format_name == MISTAKE_F) {
        format.setBackground(EDITOR_MISTAKE_BACKGROUND_COLOR);
    } else {
        format.setBackground(EDITOR_DEFAULT_BACKGROUND_COLOR);
    }

    if (format_name == DEFAULT_F) {
        format.setForeground(EDITOR_DEFAULT_TEXT_COLOR);
    } else if (format_name == MISTAKE_F) {
        format.setForeground(EDITOR_MISTAKE_TEXT_COLOR);
    } else if (format_name == KEY_F) {
        format.setForeground(EDITOR_KEY_TEXT_COLOR);
    } else if (format_name == NUMBER_F) {
        format.setForeground(EDITOR_NUMBER_TEXT_COLOR);
    } else if (format_name == STRING_F) {
        format.setForeground(EDITOR_STRING_TEXT_COLOR);
    } else if (format_name == BOOLEAN_F) {
        format.setForeground(EDITOR_BOOLEAN_TEXT_COLOR);
    } else if (format_name == NULL_F) {
        format.setForeground(EDITOR_NULL_TEXT_COLOR);
    }

    editor_->setCurrentCharFormat(format);
}

void TextHighlighter::appendText(const QString &text) {
    moveCursor(QTextCursor::End);
    editor_->insertPlainText(text);
}
