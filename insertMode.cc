#include "insertMode.h"

void InsertMode::doInsertMode() {
    Position startingPos = fileManager->getCursorPosition();
    vm->runInsertMode();
    createInsertFootprint(startingPos, fileManager->getCursorPosition());
}
