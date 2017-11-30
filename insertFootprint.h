#ifndef INSERTFOOTPRINT_H
#define INSERTFOOTPRINT_H
#include "footprint.h"
#include "range.h"

class InsertFootprint: public virtual Footprint {
    Range range;
    void undoFootprint(FileManager &fm) override;
  protected:
    void undoInsert(FileManager &fm);
  public:
    InsertFootprint(const Position &begin, const Position &end): range{begin,end} {}
};
#endif
