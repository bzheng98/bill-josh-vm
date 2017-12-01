#ifndef SCROLL_COMMAND_H
#define SCROLL_COMMAND_H

#include "cursorMotionCommand.h"

class ScrollCommand: public CursorMotionCommand {
  public:
    ScrollCommand(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        CursorMotionCommand{vm, fileManager, registerManager} {}
};
#endif
