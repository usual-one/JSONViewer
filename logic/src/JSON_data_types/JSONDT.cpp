#include "logic/include/JSON_data_types/JSONDT.h"

TextPosition &JSONDT::getBeginPos()
{
    return pos_.begin_;
}

TextPosition &JSONDT::getEndPos()
{
    return pos_.end_;
}

void JSONDT::setBeginPos(size_t row, size_t col)
{
    pos_.begin_.setPosition(row, col);
}

void JSONDT::setBeginPos(const TextPosition &pos)
{
    pos_.begin_.setPosition(pos);
}

void JSONDT::setEndPos(size_t row, size_t col)
{
    pos_.end_.setPosition(row, col);
}

void JSONDT::setEndPos(const TextPosition &pos)
{
    pos_.end_.setPosition(pos);
}
