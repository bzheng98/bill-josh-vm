#ifndef RIGHT_H
#define RIGHT_H
#include "basicMotion.h"

class Right: public BasicMotion {
  public:
    void update(const CommandInfo &c) override;
    Right(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        BasicMotion{vm, fileManager, registerManager} {}

};
#endif
