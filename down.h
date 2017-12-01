#ifndef DOWN_H
#define DOWN_H
#include "basicMotion.h"

class Down: public BasicMotion {
  public:
    void update(const CommandInfo &c) override;
    Down(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        BasicMotion{vm, fileManager, registerManager} {}

};
#endif
