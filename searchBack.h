#ifndef SEARCHBACK_H
#define SEARCHBACK_H
#include "motionCommand.h"

class SearchBack: public MotionCommand {
    bool checkCommand(const CommandInfo &c) override;
    bool isLinewise() override;
  public:
    SearchBack(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        MotionCommand{vm, fileManager, registerManager} {}
    Position getMotionResult(const CommandInfo &c) override;

};
#endif
