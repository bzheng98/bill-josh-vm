#include "position.h"

Position::Position(int line, int col): line{line}, col{col} {}

int Position::getLine() const {
    return line;
}

int Position::getCol() const {
    return col;
}

void Position::setLine(int line) {
    this -> line = line;
}

void Position::setCol(int col) {
    this -> col = col;
}

bool Position::operator<(const Position &other) const {
    return line < other.line || line == other.line && col < other.col;
}

bool Position::operator!=(const Position &other) const {
    return line != other.line || col != other.col;
}

bool Position::operator==(const Position &other) const {
    return line == other.line && col == other.col;
}
