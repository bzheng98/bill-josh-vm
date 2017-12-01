#ifndef SCROLL_UP_H
#define SCROLL_UP_H
#include "scrollCommand.h"

class ScrollUp: public ScrollCommand {
  public:
    void update(const CommandInfo &c) override;
    ScrollUp(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        ScrollCommand{vm, fileManager, registerManager} {}
};
#endif
