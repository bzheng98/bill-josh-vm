#ifndef DELETEFOOTPRINT_H
#define DELETEFOOTPRINT_H
#include "footprint.h"
#include "position.h"

class DeleteFootprint: public virtual Footprint {
    Position pos;
    Position cursorPos;
    std::string deleted;
    void undoFootprint(FileManager &fm) override;
  protected:
    void undoDelete(FileManager &fm);
  public:
    DeleteFootprint(const Position &pos, const std::string &deleted, bool keepUndoing = false): Footprint{keepUndoing}, pos{pos}, cursorPos{pos}, deleted{deleted} {}
    DeleteFootprint(const Position &pos, const std::string &deleted, const Position &cursor, bool keepUndoing = false): Footprint{keepUndoing}, pos{pos}, cursorPos{cursor}, deleted{deleted} {}
};
#endif
