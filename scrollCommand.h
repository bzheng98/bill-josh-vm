#ifndef SCROLL_COMMAND_H
#define SCROLL_COMMAND_H

#include "cursorMotionCommand.h"

class ScrollCommand: public CursorMotionCommand {
    protected:
        ScrollCommand(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
            CursorMotionCommand{vm, fileManager, registerManager} {}
};
#endif
