#ifndef POSITION_H
#define POSITION_H

class Position {
    int line, col;
public:
    Position(int line, int col);
    int getLine();
    int getCol();
    void setLine();
    void setCol();
};
#endif
