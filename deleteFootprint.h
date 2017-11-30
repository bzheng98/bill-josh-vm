#ifndef DELETEFOOTPRINT_H
#define DELETEFOOTPRINT_H
#include "footprint.h"
#include "position.h"

class DeleteFootprint: public virtual Footprint {
    Position pos;
    std::string deleted;
  public:
    DeleteFootprint(const Position &pos, const std::string &deleted): pos{pos}, deleted{deleted} {}
};
#endif
