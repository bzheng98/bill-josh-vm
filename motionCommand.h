#ifndef MOTION_COMMAND_H
#define MOTION_COMMAND_H

#include "cursorMotionCommand.h"

class MotionCommand: public CursorMotionCommand {
  public:
    MotionCommand(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        CursorMotionCommand{vm, fileManager, registerManager} {}
};
#endif
