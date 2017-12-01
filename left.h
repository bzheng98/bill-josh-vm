#ifndef LEFT_H
#define LEFT_H
#include "basicMotion.h"

class Left: public BasicMotion {
  public:
    void update(const CommandInfo &c) override;
    Left(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        BasicMotion{vm, fileManager, registerManager} {}

};
#endif
