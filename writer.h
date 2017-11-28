#ifndef WRITER_H
#define WRITER_H

#include "fileCommand.h"

class Writer: public FileCommand {
  protected:
    Writer(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        FileCommand{vm, fileManager, registerManager} {}
    void save();
};
#endif
