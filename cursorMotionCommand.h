#ifndef CURSOR_MOTION_COMMAND_H
#define CURSOR_MOTION_COMMAND_H

#include "command.h"
#include "position.h"

class CursorMotionCommand: public virtual Command {
  public:
    CursorMotionCommand(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager} {}
};
#endif
