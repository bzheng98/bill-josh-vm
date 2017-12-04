#ifndef FOOTPRINT_H
#define FOOTPRINT_H
#include "range.h"
#include "fileManager.h"
#include <utility>

class Footprint {
    bool keepUndoing;
    void virtual undoFootprint(FileManager &fm) = 0;
  protected:
    Footprint(bool keepUndoing): keepUndoing{keepUndoing} {};
  public:
    bool undo(FileManager &fm);
    virtual ~Footprint() {}
};
#endif
