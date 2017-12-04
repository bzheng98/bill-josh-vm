#include "footprint.h"

bool Footprint::undo(FileManager &fm) {
    undoFootprint(fm);
    return !keepUndoing;
}
