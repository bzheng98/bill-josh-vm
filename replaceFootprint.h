#ifndef REPLACEFOOTPRINT_H
#define REPLACEFOOTPRINT_H
#include "insertFootprint.h"
#include "deleteFootprint.h"

class ReplaceFootprint: public InsertFootprint, public DeleteFootprint {
    void undoFootprint(FileManager &fm) override;
  public:
    ReplaceFootprint(const Position &begin, const Position &end, const std::string &replaced, const Position &cursor, bool keepUndoing = false):
        Footprint{keepUndoing},
        InsertFootprint{begin,end, keepUndoing},
        DeleteFootprint{begin, replaced, cursor, keepUndoing} {}
};
#endif
