#ifndef FINDFORWARD_H
#define FINDFORWARD_H
#include "motionCommand.h"

class FindForward: public MotionCommand {
    bool checkCommand(const CommandInfo &c) override;
    bool isLinewise() override;
  public:
    FindForward(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        MotionCommand{vm, fileManager, registerManager} {}
    Position getMotionResult(const CommandInfo &c) override;

};
#endif
