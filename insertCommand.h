#ifndef INSERT_COMMAND_H
#define INSERT_COMMAND_H

#include "command.h"
#include "position.h"

class InsertCommand: public virtual Command {
  protected:
    void createInsertFootprint(const Position &start, const Position &end, const Position &cursor);
  public:
    InsertCommand(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager} {}
};
#endif
