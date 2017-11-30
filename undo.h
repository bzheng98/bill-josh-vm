#ifndef UNDO_H
#define UNDO_H

#include "command.h"

class Undo: public Command {
  public:
    Undo(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager} {}
    void update(const CommandInfo &c) override;
};
#endif
