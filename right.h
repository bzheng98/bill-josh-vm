#ifndef RIGHT_H
#define RIGHT_H
#include "basicMotion.h"

class Right: public BasicMotion {
    bool checkCommand(const CommandInfo &c) override;
    Position getMotionResult(const CommandInfo &c) override;
    bool isChangeCol() override;
  public:
    Right(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        BasicMotion{vm, fileManager, registerManager} {}

};
#endif
