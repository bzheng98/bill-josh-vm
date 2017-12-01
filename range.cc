#include "range.h"
#include <utility>

Range::Range(const Position &start, const Position &end): start{start}, end{end} {
    if (end < start) std::swap(this->start,this->end);
}

const Position &Range::getStart() const {
    return start;
}

const Position &Range::getEnd() const {
    return end;
}
