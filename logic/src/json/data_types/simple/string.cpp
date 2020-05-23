#include "logic/include/json/data_types/simple/string.h"
#include "logic/include/json/exception/stringexception.h"
#include "logic/include/json/syntax/single_elements/lineseparator.h"
#include "logic/include/json/syntax/charsets/dt/dtcharset.h"
#include "logic/include/json/syntax/charsets/dt/stringcharset.h"

size_t String::fromStdString(const std::string &string) {
    setEndPos(getBeginPos());
    getEndPos().setColumn(getEndPos().getColumn());
    instance_.clear();

    size_t char_consumed = 0;
    if (!DTCharSet::startsLike(string, STRING_DT)) {
        throw StringQuotationBeginException("no begin qoutation found", getEndPos());
    }
    char_consumed += StringCharSet::getBorder().size();


    for (size_t i = char_consumed; i < string.size(); i++) {
        getEndPos().nextCharacter();
        if (DTCharSet::endsLike(string.substr(0, i + 1), STRING_DT) && i) {
            char_consumed = i + 1;
            break;
        }
        instance_.append(1, string[i]);
        if (LineSeparator::isEqual(string[i])) {
            getEndPos().nextLine();
        }
    }

    if (DTCharSet::endsLike(string.substr(0, char_consumed - 1), STRING_DT)) {
        throw StringQuotationEndException("no end quotation found", getEndPos());
    }
    return char_consumed;
}

std::string String::toStdString() {
    return StringCharSet::getBorder() + instance_ + StringCharSet::getBorder();
}

std::vector<TextElement> String::toTextElements(Indent indent) {
    return {TextElement(toStdString(), indent, STRING_F)};
}
