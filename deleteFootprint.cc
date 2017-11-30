#include "deleteFootprint.h"

void DeleteFootprint::undoFootprint(FileManager &fm) {
    undoDelete(fm);
}

void DeleteFootprint::undoDelete(FileManager &fm) {
    fm.insertText(deleted, pos);
}
