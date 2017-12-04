#ifndef SEARCHFORWARD_H
#define SEARCHFORWARD_H
#include "motionCommand.h"

class SearchForward: public MotionCommand {
    bool checkCommand(const CommandInfo &c) override;
    bool isLinewise() override;
  public:
    SearchForward(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        MotionCommand{vm, fileManager, registerManager} {}
    Position getMotionResult(const CommandInfo &c) override;
};
#endif
