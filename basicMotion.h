#ifndef BASIC_MOTION_H
#define BASIC_MOTION_H
#include "motionCommand.h"

class BasicMotion: public MotionCommand {
  public:
    BasicMotion(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        MotionCommand{vm, fileManager, registerManager} {}
    void moveCursor(int dx, int dy);
};
#endif
