#ifndef LEFT_H
#define LEFT_H
#include "basicMotion.h"

class Left: public BasicMotion {
    bool checkCommand(const CommandInfo &c) override;
    bool isLinewise() override;
  public:
    Left(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        BasicMotion{vm, fileManager, registerManager} {}
    Position getMotionResult(const CommandInfo &c) override;

};
#endif
