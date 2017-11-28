#ifndef FILE_COMMAND_H
#define FILE_COMMAND_H

#include "command.h"

class FileCommand: public Command {
  protected:
    FileCommand(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager} {}
};
#endif
