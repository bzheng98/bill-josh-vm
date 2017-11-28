#ifndef INSERTFOOTPRINT_H
#define INSERTFOOTPRINT_H
#include "footprint.h"

class InsertFootprint: public Footprint {
  public:
    InsertFootprint(const Position &begin, const Position &end): Footprint{Range(begin,end)} {}
};
#endif
