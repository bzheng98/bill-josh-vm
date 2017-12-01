#ifndef WRITEREGISTERCOMMAND_H
#define WRITEREGISTERCOMMAND_H

#include "command.h"

class WriteRegisterCommand: public virtual Command {
  public:
    WriteRegisterCommand(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager} {}
};
#endif
