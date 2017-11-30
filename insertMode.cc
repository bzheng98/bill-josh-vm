#include "insertMode.h"
#include <string>

void InsertMode::doInsertMode(int count) {
    Position startingPos = fileManager->getCursorPosition();
    std::string s = vm->runInsertMode();
    if (count > 1)
        fileManager->insertText(s, fileManager->getCursorPosition(), count-1);
    createInsertFootprint(startingPos, fileManager->getCursorPosition());
}
