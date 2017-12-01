#ifndef INSERTFOOTPRINT_H
#define INSERTFOOTPRINT_H
#include "footprint.h"
#include "range.h"

class InsertFootprint: public virtual Footprint {
    Range range;
    Position cursor;
    void undoFootprint(FileManager &fm) override;
  protected:
    void undoInsert(FileManager &fm);
  public:
    InsertFootprint(const Position &begin, const Position &end, const Position &cursor): range{begin,end}, cursor{cursor} {}
    InsertFootprint(const Position &begin, const Position &end): range{begin,end}, cursor{begin} {}
};
#endif
