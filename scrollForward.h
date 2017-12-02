#ifndef SCROLL_FORWARD_H
#define SCROLL_FORWARD_H
#include "scrollCommand.h"

class ScrollForward: public ScrollCommand {
  public:
    void update(const CommandInfo &c) override;
    ScrollForward(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        ScrollCommand{vm, fileManager, registerManager} {}
};
#endif
