#ifndef UP_H
#define UP_H
#include "basicMotion.h"

class Up: public BasicMotion {
  public:
    void update(const CommandInfo &c) override;
    Up(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        BasicMotion{vm, fileManager, registerManager} {}

};
#endif
