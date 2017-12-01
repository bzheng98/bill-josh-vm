#ifndef WRITEREGISTERCOMMAND_H
#define WRITEREGISTERCOMMAND_H

#include "command.h"
#include <string>

class WriteRegisterCommand: public virtual Command {
  protected:
    void writeToRegister(const std::string &s);
  public:
    WriteRegisterCommand(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager} {}
};
#endif
