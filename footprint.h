#ifndef FOOTPRINT_H
#define FOOTPRINT_H
#include "range.h"
#include "fileManager.h"
#include <utility>

class Footprint {
    void virtual undoFootprint(FileManager &fm) = 0;
  protected:
    Footprint() = default;
  public:
    void undo(FileManager &fm);
};
#endif
