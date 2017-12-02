#ifndef MOTION_COMMAND_H
#define MOTION_COMMAND_H

#include "cursorMotionCommand.h"
#include "position.h"

class MotionCommand: public CursorMotionCommand {
    bool virtual checkCommand(const CommandInfo &c);
    Position virtual getMotionResult(const CommandInfo &c);
    bool virtual isLinewise();
  public:
    MotionCommand(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        CursorMotionCommand{vm, fileManager, registerManager} {}
    void update(const CommandInfo &c) final;
};
#endif
