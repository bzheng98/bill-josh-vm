#ifndef FORCEQUIT_H
#define FORCEQUIT_H

#include "quitter.h"

class ForceQuit: public Quitter {
  public:
    ForceQuit(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        FileCommand{vm, fileManager, registerManager},
        Quitter{vm, fileManager, registerManager} {}
    void update(const CommandInfo &c) override;
};
#endif
