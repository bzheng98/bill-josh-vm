#ifndef DELETEFOOTPRINT_H
#define DELETEFOOTPRINT_H
#include "footprint.h"
#include "position.h"

class DeleteFootprint: public virtual Footprint {
    Position pos;
    std::string deleted;
    void undoFootprint(FileManager &fm) override;
  protected:
    void undoDelete(FileManager &fm);
  public:
    DeleteFootprint(const Position &pos, const std::string &deleted): pos{pos}, deleted{deleted} {}
};
#endif
