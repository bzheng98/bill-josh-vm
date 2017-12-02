#ifndef SCROLL_BACKWARD_H
#define SCROLL_BACKWARD_H
#include "scrollCommand.h"

class ScrollBackward: public ScrollCommand {
  public:
    void update(const CommandInfo &c) override;
    ScrollBackward(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        ScrollCommand{vm, fileManager, registerManager} {}
};
#endif
