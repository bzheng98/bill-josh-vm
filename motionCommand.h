#ifndef MOTION_COMMAND_H
#define MOTION_COMMAND_H

#include "cursorMotionCommand.h"

class MotionCommand: public CursorMotionCommand {
  protected:
    MotionCommand(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        CursorMotionCommand{vm, fileManager, registerManager} {}
};
#endif
