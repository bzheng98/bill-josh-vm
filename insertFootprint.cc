#include "insertFootprint.h"

void InsertFootprint::undoFootprint(FileManager &fm) {
    undoInsert(fm);
}

void InsertFootprint::undoInsert(FileManager &fm) {
    fm.deleteText(range);
    fm.setCursorPosition(cursor);
}
