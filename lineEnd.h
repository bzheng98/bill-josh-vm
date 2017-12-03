#ifndef LINEEND_H
#define LINEEND_H
#include "motionCommand.h"

class LineEnd: public MotionCommand {
    bool checkCommand(const CommandInfo &c) override;
    bool isLinewise() override;
  public:
    LineEnd(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        MotionCommand{vm, fileManager, registerManager} {}
    Position getMotionResult(const CommandInfo &c) override;

};
#endif
