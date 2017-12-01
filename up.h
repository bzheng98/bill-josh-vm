#ifndef UP_H
#define UP_H
#include "basicMotion.h"

class Up: public BasicMotion {
    bool checkCommand(const CommandInfo &c) override;
    Position getMotionResult(const CommandInfo &c) override;
    bool isChangeCol() override;
  public:
    Up(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        BasicMotion{vm, fileManager, registerManager} {}

};
#endif
