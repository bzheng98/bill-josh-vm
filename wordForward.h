#ifndef WORDFORWARD_H
#define WORDFORWARD_H
#include "motionCommand.h"

class WordForward: public MotionCommand {
    bool checkCommand(const CommandInfo &c) override;
    Position getMotionResult(const CommandInfo &c) override;
    bool isChangeCol() override;
  public:
    WordForward(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        MotionCommand{vm, fileManager, registerManager} {}

};
#endif
