#ifndef FOOTPRINT_H
#define FOOTPRINT_H
#include "range.h"
#include <utility>

class Footprint {
    Range range;
  protected:
    Footprint(const Range &range): range{std::move(range)} {}
  public:
    const Range &getRange();
};
#endif
