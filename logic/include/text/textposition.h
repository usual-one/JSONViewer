#ifndef UTILS_TEXTPOSITION_H
#define UTILS_TEXTPOSITION_H

#include <cstddef>

class TextPosition {
public:
    TextPosition();

    TextPosition(int row, int col);

    void setPosition(int row, int col);

    void setPosition(const TextPosition &pos);

    void setRow(int row);

    void setColumn(int col);

    int getRow() const;

    int getColumn() const;

    void nextCharacter();

    void nextLine();

private:
    int row_;

    int column_;
};

#endif // UTILS_TEXTPOSITION_H
