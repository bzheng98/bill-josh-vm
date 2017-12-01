#ifndef DOWN_H
#define DOWN_H
#include "basicMotion.h"

class Down: public BasicMotion {
    bool checkCommand(const CommandInfo &c) override;
    Position getMotionResult(const CommandInfo &c) override;
    bool isChangeCol() override;
  public:
    Down(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        BasicMotion{vm, fileManager, registerManager} {}

};
#endif
