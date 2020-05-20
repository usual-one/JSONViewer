#ifndef DATA_TYPES_JSONDT_H
#define DATA_TYPES_JSONDT_H

#include "logic/include/utils/TextPosition.h"
#include "UI/include/printing/texthighlighter.h"
#include "logic/include/utils/TextElement.h"

#include <string>
#include <vector>

class JSONDT {
public:
    virtual size_t fromStdString(const std::string &string) = 0;

    virtual std::string toStdString() = 0;

//    virtual void printOnWidget(TextHighlighter &highlighter, const std::string &prefix = "") = 0;

    virtual std::vector<TextElement> toTextElements(Indent indent) = 0;

    TextPosition &getBeginPos();

    TextPosition &getEndPos();

    void setBeginPos(size_t row, size_t col);

    void setBeginPos(const TextPosition &pos);

    void setEndPos(size_t row, size_t col);

    void setEndPos(const TextPosition &pos);

protected:
    struct {
        TextPosition begin_;

        TextPosition end_;
    } pos_;
};

#endif // DATA_TYPES_JSONDT_H
