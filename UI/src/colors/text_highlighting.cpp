#include "UI/include/colors/text_highlighting.h"
#include "UI/include/colors/TextHighlighter.h"

void highlightMistake(QPlainTextEdit *text_edit, const QString &json, const TextPosition &pos) {
    TextPosition temp_pos(pos);
    TextHighlighter high_lighter(text_edit);
    high_lighter.clear();

    for (int i = 0; i < json.size(); i++) {
        if (!temp_pos.getRow()) {
            if (!temp_pos.getColumn()) {
                high_lighter.print(json.left(i));
                high_lighter.printMistake(json.mid(i, 1));
                high_lighter.print(json.right(json.size() - i - 1));
                return;
            }
            temp_pos.setColumn(temp_pos.getColumn() - 1);
        }
        if (json.at(i) == '\n') {
            temp_pos.setRow(temp_pos.getRow() - 1);
        }
    }
}
