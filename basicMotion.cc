#include "basicMotion.h"

void BasicMotion::moveCursor(int dx, int dy) {
    Position cur = fileManager -> getCursorPosition();
    cur.setCol(cur.getCol() + dx);
    cur.setLine(cur.getLine() + dy);
    fileManager -> setCursorPosition(cur);
}
