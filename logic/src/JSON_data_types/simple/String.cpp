#include "logic/include/JSON_data_types/simple/String.h"
#include "logic/include/exception/JSON_DT/StringException.h"

size_t String::fromStdString(const std::string &string)
{
    setEndPos(getBeginPos());
    getEndPos().setColumn(getEndPos().getColumn() - 1);
    instance_.clear();

    if (string[0] != '"') {
        throw StringQuotationBeginException("no begin qoutation found", getEndPos());
    }

     for (size_t i = 0; i < string.size(); i++) {
         getEndPos().setColumn(getEndPos().getColumn() + 1);
         instance_.append(1, string[i]);
         if (string[i] == '\n') {
             getEndPos().setRow(getEndPos().getRow() + 1);
             getEndPos().setColumn(-1);
         }
         if (string[i] == '"' && i) {
             break;
         }
     }
     if (instance_[instance_.size() - 1] != '"') {
         throw StringQuotationEndException("no end quotation found", getEndPos());
     }
     return instance_.size();
}

std::string String::toStdString(const std::string &prefix)
{
    return prefix + "\"" + instance_ + "\"";
}
