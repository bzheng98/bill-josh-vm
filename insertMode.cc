#include "insertMode.h"
#include <string>
#include "vm.h"
#include "fileManager.h"

void InsertMode::doInsertMode(int count, Position originalCursor, bool newline) {
    Position startingPos = fileManager->getCursorPosition();
    std::string s;
    vm->runInsertMode(s);
    if (count > 1)
        fileManager->insertText(s, fileManager->getCursorPosition(), count-1);
    Position endingPos = fileManager->getCursorPosition();
    if (newline) {
        endingPos.setLine(endingPos.getLine()+1);
        endingPos.setCol(0);
    }
    if (startingPos < endingPos)
        createInsertFootprint(startingPos, endingPos, originalCursor);
    fileManager->leaveInsertMode();
}
