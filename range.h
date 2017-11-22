#ifndef RANGE_H
#define RANGE_H
#include "position.h"

class Range {
    Position start, end;
public:
    Position getStart();
    Position getEnd();
};
#endif
