#ifndef CURSOR_MOTION_COMMAND_H
#define CURSOR_MOTION_COMMAND_H

#include "command.h"
#include "position.h"

class CursorMotionCommand: public Command {
  protected:
    CursorMotionCommand(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager} {}
};
#endif
