#ifndef REPLACEFOOTPRINT_H
#define REPLACEFOOTPRINT_H
#include "insertFootprint.h"
#include "deleteFootprint.h"

class ReplaceFootprint: public InsertFootprint, public DeleteFootprint {
  public:
    ReplaceFootprint(const Position &begin, const Position &end, const std::string &replaced):
        Footprint{},
        InsertFootprint{begin,end},
        DeleteFootprint{begin, replaced} {}
};
#endif
