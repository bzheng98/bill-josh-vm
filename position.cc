#include "position.h"

Position::Position(int line, int col): line{line}, col{col} {}

int Position::getLine() {
    return line;
}

int Position::getCol() {
    return col;
}

void Position::setLine(int line) {
    this -> line = line;
}

void Position::setCol(int col) {
    this -> col = col;
}
