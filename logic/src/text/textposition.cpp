#include "logic/include/text/textposition.h"

TextPosition::TextPosition()
{
    setPosition(0, 0);
}

TextPosition::TextPosition(int row, int col)
{
    setPosition(row, col);
}

void TextPosition::setPosition(int row, int col)
{
    setRow(row);
    setColumn(col);
}

void TextPosition::setPosition(const TextPosition &pos)
{
    setRow(pos.row_);
    setColumn(pos.column_);
}

void TextPosition::setRow(int row)
{
    row_ = row;
}

void TextPosition::setColumn(int col)
{
    column_ = col;
}

int TextPosition::getRow() const
{
    return row_;
}

int TextPosition::getColumn() const
{
    return column_;
}
