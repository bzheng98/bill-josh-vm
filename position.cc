#include "position.h"

Position::Position(size_t line, size_t col): line{line}, col{col} {}

size_t Position::getLine() const {
    return line;
}

size_t Position::getCol() const {
    return col;
}

void Position::setLine(size_t line) {
    this -> line = line;
}

void Position::setCol(size_t col) {
    this -> col = col;
}
