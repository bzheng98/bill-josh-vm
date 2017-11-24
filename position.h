#ifndef POSITION_H
#define POSITION_H
#include <cstddef>

class Position {
    size_t line, col;
public:
    Position(size_t line, size_t col);
    size_t getLine() const;
    size_t getCol() const;
    void setLine(size_t line);
    void setCol(size_t col);
};
#endif
