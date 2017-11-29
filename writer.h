#ifndef WRITER_H
#define WRITER_H

#include "fileCommand.h"

class Writer: public virtual FileCommand {
  protected:
    void save();
    void update(const CommandInfo &c) override;
  public:
    Writer(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        FileCommand{vm, fileManager, registerManager} {}
};
#endif
