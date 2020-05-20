#include "logic/include/JSON_data_types/simple/String.h"
#include "logic/include/exception/JSON_DT/StringException.h"
#include "logic/include/syntax_config.h"

size_t String::fromStdString(const std::string &string) {
    setEndPos(getBeginPos());
    getEndPos().setColumn(getEndPos().getColumn());
    instance_.clear();

    size_t char_consumed = 0;
    if (string[0] != STRING_BORDER[0]) {
        throw StringQuotationBeginException("no begin qoutation found", getEndPos());
    }
    char_consumed++;


    for (size_t i = char_consumed; i < string.size(); i++) {
        getEndPos().setColumn(getEndPos().getColumn() + 1);
        if (string[i] == STRING_BORDER[0] && i) {
            char_consumed = i + 1;
            break;
        }
        instance_.append(1, string[i]);
        if (string[i] == '\n') {
            getEndPos().setRow(getEndPos().getRow() + 1);
            getEndPos().setColumn(-1);
        }
    }

    if (string[char_consumed - 1] != STRING_BORDER[0]) {
        throw StringQuotationEndException("no end quotation found", getEndPos());
    }
    return char_consumed;
}

std::string String::toStdString() {
    return STRING_BORDER + instance_ + STRING_BORDER;
}

std::vector<TextElement> String::toTextElements(Indent indent) {
    return {TextElement(toStdString(), indent, STRING_F)};
}
