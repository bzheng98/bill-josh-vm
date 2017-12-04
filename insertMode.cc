#include "insertMode.h"
#include <string>
#include "vm.h"
#include "fileManager.h"
#include "replaceFootprint.h"

void InsertMode::doInsertMode(int count, Position originalCursor, bool newline, bool replaceMotion) {
    Position startingPos = fileManager->getCursorPosition();
    std::string inserted;
    std::string deleted = vm->runInsertMode(inserted);
    if (newline) inserted.push_back('\n');
    Position original = fileManager->getCursorPosition();
    for (int i = 0; i < inserted.length() - (newline? 1:0); ++i) fileManager->setCursorPosition(fileManager->cursor.getPrev(true), false, true);
    Position start = fileManager->getCursorPosition();
    fileManager->setCursorPosition(original, false, true);
    Position end = original;
    if (newline) {
        end.setLine(end.getLine()+1);
        end.setCol(0);
    }
    std::unique_ptr<Footprint> r{new ReplaceFootprint{start, end, deleted, originalCursor}};

    r->undo(*fileManager);
    fileManager->setCursorPosition(startingPos, false, true);
    deleted = fileManager->replaceText(deleted.length(), inserted, count);
    if (inserted.length() > deleted.length()) {
        std::string actual;
        for (int i = 0; i < count-1; ++i) {
            actual += inserted.substr(0,inserted.length()-deleted.length());
        }
        actual += inserted;
        inserted = actual;
    }
    original = fileManager->getCursorPosition();
    for (int i = 0; i < inserted.length(); ++i) fileManager->setCursorPosition(fileManager->cursor.getPrev(true), false, true);
    start = fileManager->getCursorPosition();
    fileManager->setCursorPosition(original, false, true);
    end = original;
    if (start < end || deleted.size())
        createReplaceFootprint(start, end, deleted, originalCursor, replaceMotion);
    if (newline) {
        fileManager->moveCursorPosition(0, -1);
        fileManager->goToEndOfLine(true);
    }
    fileManager->leaveInsertMode();
}
