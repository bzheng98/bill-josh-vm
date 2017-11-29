#ifndef QUIT_H
#define QUIT_H

#include "quitter.h"

class Quit: public Quitter {
  public:
    Quit(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        FileCommand{vm, fileManager, registerManager},
        Quitter{vm, fileManager, registerManager} {}
    void update(const CommandInfo &c) override;
};
#endif
