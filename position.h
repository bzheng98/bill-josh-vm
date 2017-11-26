#ifndef POSITION_H
#define POSITION_H
#include <cstddef>

class Position {
    int line, col;
public:
    Position(int line, int col);
    int getLine() const;
    int getCol() const;
    void setLine(int line);
    void setCol(int col);
};
#endif
