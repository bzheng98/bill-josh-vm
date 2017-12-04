#ifndef QUITTER_H
#define QUITTER_H

#include "fileCommand.h"

class Quitter: public virtual FileCommand {
  protected:
    void quit(bool wrote = true);
  public:
    Quitter(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        FileCommand{vm, fileManager, registerManager} {}
};
#endif
