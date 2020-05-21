#include "UI/include/output/texthighlighter.h"
#include "config.h"
#include EDITOR_COLOR_SCHEME


TextHighlighter::TextHighlighter() {
    editor_ = nullptr;
}

TextHighlighter::TextHighlighter(QPlainTextEdit *editor) {
    editor_ = editor;
}

void TextHighlighter::clear() {
    editor_->clear();
    editor_->moveCursor(QTextCursor::Start);
}

void TextHighlighter::print(const QString &text, CharFormatName format_name) {
    setCharFormat(format_name);
    appendText(text);
}

void TextHighlighter::printMistake(const QString &text) {
    print(text, MISTAKE_F);
}

void TextHighlighter::printKey(const QString &text) {
    print(text, KEY_F);
}

void TextHighlighter::printNumber(const QString &text) {
    print(text, NUMBER_F);
}

void TextHighlighter::printString(const QString &text) {
    print(text, STRING_F);
}

void TextHighlighter::printBoolean(const QString &text) {
    print(text, BOOLEAN_F);
}

void TextHighlighter::printNull(const QString &text) {
    print(text, NULL_F);
}

void TextHighlighter::printTextElements(const QVector<TextElement> &elements) {
    for (auto elem : elements) {
        print(QString::fromStdString(elem.getIndent()));
        print(QString::fromStdString(elem.getText()), elem.getFormat());
    }
}

void TextHighlighter::printMistakeHighlighted(const QString &text, const TextPosition &pos) {
    clear();
    TextPosition temp_pos(pos);

    int needed_pos;
    for (int i = 0; i < text.size(); i++) {
        if (!temp_pos.getRow()) {
            if (!temp_pos.getColumn()) {
                print(text.left(i));
                moveCursor(QTextCursor::End);
                needed_pos = editor_->textCursor().position();

                printMistake(text.mid(i, 1));
                print(text.right(text.size() - i - 1));
                moveCursor(needed_pos);
                return;
            }
            temp_pos.setColumn(temp_pos.getColumn() - 1);
        }
        if (text.at(i) == '\n') {
            temp_pos.setRow(temp_pos.getRow() - 1);
        }
    }
}

void TextHighlighter::moveCursor(const QTextCursor::MoveOperation &op) {
    QTextCharFormat format = editor_->currentCharFormat();
    editor_->moveCursor(op);
    editor_->setCurrentCharFormat(format);
}

void TextHighlighter::moveCursor(const QTextCursor &cursor){
    QTextCharFormat format = editor_->currentCharFormat();
    editor_->setTextCursor(cursor);
    editor_->setCurrentCharFormat(format);
}

void TextHighlighter::moveCursor(size_t pos) {
    QTextCharFormat format = editor_->currentCharFormat();
    QTextCursor cursor = editor_->textCursor();
    cursor.setPosition(pos);
    editor_->setTextCursor(cursor);
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
    int current_pos = editor_->textCursor().position();
    moveCursor(QTextCursor::End);
    editor_->insertPlainText(text);
    moveCursor(current_pos);
}
