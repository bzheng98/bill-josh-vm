#include "replaceFootprint.h"

void ReplaceFootprint::undoFootprint(FileManager &fm) {
    undoInsert(fm);
    undoDelete(fm);
}
