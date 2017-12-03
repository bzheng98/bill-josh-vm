#ifndef WRITER_H
#define WRITER_H

#include "fileCommand.h"
#include <string>

class Writer: public virtual FileCommand {
  protected:
    void save(const std::string &s);
  public:
    Writer(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        FileCommand{vm, fileManager, registerManager} {}
};
#endif
