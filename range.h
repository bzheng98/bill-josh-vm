#ifndef RANGE_H
#define RANGE_H
#include "position.h"

class Range {
    Position start, end;
public:
    const Position &getStart() const;
    const Position &getEnd() const;
};
#endif
