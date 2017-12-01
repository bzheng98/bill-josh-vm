#ifndef WORDBACK_H
#define WORDBACK_H
#include "motionCommand.h"

class WordBack: public MotionCommand {
    bool checkCommand(const CommandInfo &c) override;
    Position getMotionResult(const CommandInfo &c) override;
    bool isChangeCol() override;
  public:
    WordBack(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        MotionCommand{vm, fileManager, registerManager} {}

};
#endif
