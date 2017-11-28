#ifndef INSERT_COMMAND_H
#define INSERT_COMMAND_H

#include "command.h"
#include "position.h"

class InsertCommand: public Command {
  protected:
    InsertCommand(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager} {}
    void createInsertFootprint(const Position &start, const Position &end);
};
#endif
