#ifndef RANGE_H
#define RANGE_H
#include "position.h"

class Range {
    Position start, end;
  public:
    Range(const Position &start, const Position &end): start{start}, end{end} {}
    const Position &getStart() const;
    const Position &getEnd() const;
};
#endif
