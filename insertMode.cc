#include "insertMode.h"
#include <string>

void InsertMode::doInsertMode(int count) {
    Position startingPos = fileManager->getCursorPosition();
    std::string s;
    vm->runInsertMode(s);
    if (count > 1)
        fileManager->insertText(s, fileManager->getCursorPosition(), count-1);
    const Position &endingPos = fileManager->getCursorPosition();
    if (startingPos < endingPos)
        createInsertFootprint(startingPos, fileManager->getCursorPosition());
    fileManager->leaveInsertMode();
}
