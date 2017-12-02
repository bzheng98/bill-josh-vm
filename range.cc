#include "range.h"
#include <utility>

Range::Range(const Position &start, const Position &end): start{start}, end{end} {
    if (end < start) std::swap(this->start,this->end);
}

void Range::makeLinewise() {
    start.setCol(0);
    end.setLine(end.getLine()+1);
    end.setCol(0);
}

const Position &Range::getStart() const {
    return start;
}

const Position &Range::getEnd() const {
    return end;
}
