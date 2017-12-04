#include "insertMode.h"
#include <string>
#include "vm.h"
#include "fileManager.h"

void InsertMode::doInsertMode(int count, Position originalCursor, bool newline) {
    Position startingPos = fileManager->getCursorPosition();
    std::string inserted;
    std::string deleted = vm->runInsertMode(inserted);
    if (newline) inserted.push_back('\n');
    if (count > 1)
        fileManager->insertText(inserted, fileManager->getCursorPosition(), count-1);
    Position original = fileManager->getCursorPosition();
    for (int i = 0; i < inserted.length() - (newline? 1:0); ++i) fileManager->setCursorPosition(fileManager->cursor.getPrev(true), false, true);
    Position start = fileManager->getCursorPosition();
    fileManager->setCursorPosition(original, false, true);
    Position end = original;
    if (newline) {
        end.setLine(end.getLine()+1);
        end.setCol(0);
    }
    if (start < end || deleted.size())
        createReplaceFootprint(start, end, deleted, originalCursor);
    fileManager->leaveInsertMode();
}
