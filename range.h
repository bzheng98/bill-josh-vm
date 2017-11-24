#ifndef RANGE_H
#define RANGE_H
#include "position.h"

class Range {
    Position start, end;
public:
    Position getStart() const;
    Position getEnd() const;
};
#endif
