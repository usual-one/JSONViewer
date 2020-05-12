#include "logic/include/JSON_data_types/simple/String.h"
#include "logic/include/exception/JSON_DT/StringException.h"

size_t String::fromStdString(const std::string &string) {
    setEndPos(getBeginPos());
    getEndPos().setColumn(getEndPos().getColumn());
    instance_.clear();

    size_t char_consumed = 0;
    if (string[0] != '"') {
        throw StringQuotationBeginException("no begin qoutation found", getEndPos());
    }
    char_consumed++;


    for (size_t i = char_consumed; i < string.size(); i++) {
        getEndPos().setColumn(getEndPos().getColumn() + 1);
        if (string[i] == '"' && i) {
            char_consumed = i + 1;
            break;
        }
        instance_.append(1, string[i]);
        if (string[i] == '\n') {
            getEndPos().setRow(getEndPos().getRow() + 1);
            getEndPos().setColumn(-1);
        }
    }

    if (string[char_consumed - 1] != '"') {
        throw StringQuotationEndException("no end quotation found", getEndPos());
    }
    return char_consumed;
}

std::string String::toStdString() {
    return "\"" + instance_ + "\"";
}

void String::printOnWidget(TextHighlighter &highlighter, const std::string &prefix) {
    highlighter.printString((prefix + toStdString()).data());
}
