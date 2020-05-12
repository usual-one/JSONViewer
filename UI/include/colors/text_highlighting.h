#ifndef TEXT_HIGHLIGHTING_H
#define TEXT_HIGHLIGHTING_H

#include "logic/include/utils/TextPosition.h"

#include <QPlainTextEdit>

void highlightMistake(QPlainTextEdit *text_edit, const QString &json, const TextPosition &pos);

#endif // TEXT_HIGHLIGHTING_H
