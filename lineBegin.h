#ifndef LINEBEGIN_H
#define LINEBEGIN_H
#include "motionCommand.h"

class LineBegin: public MotionCommand {
    bool checkCommand(const CommandInfo &c) override;
    bool isLinewise() override;
  public:
    LineBegin(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        MotionCommand{vm, fileManager, registerManager} {}
    Position getMotionResult(const CommandInfo &c) override;

};
#endif
