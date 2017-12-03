#ifndef JUMPTOMATCH_H
#define JUMPTOMATCH_H
#include "motionCommand.h"

class JumpToMatch: public MotionCommand {
    bool checkCommand(const CommandInfo &c) override;
    bool isLinewise() override;
  public:
    JumpToMatch(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        MotionCommand{vm, fileManager, registerManager} {}
    Position getMotionResult(const CommandInfo &c) override;
};
#endif
