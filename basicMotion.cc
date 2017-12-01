#include "basicMotion.h"
#include "fileManager.h"

void BasicMotion::moveCursor(int dx, int dy) {
    fileManager -> moveCursorPosition(dx, dy);
}
