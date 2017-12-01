#ifndef UP_H
#define UP_H
#include "basicMotion.h"

class Up: public BasicMotion {
    bool checkCommand(const CommandInfo &c) override;
    bool isLinewise() override;
  public:
    Up(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        BasicMotion{vm, fileManager, registerManager} {}
    Position getMotionResult(const CommandInfo &c) override;

};
#endif
