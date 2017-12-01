#ifndef SCROLL_DOWN_H
#define SCROLL_DOWN_H
#include "scrollCommand.h"

class ScrollDown: public ScrollCommand {
  public:
    void update(const CommandInfo &c) override;
    ScrollDown(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager},
        ScrollCommand{vm, fileManager, registerManager} {}
};
#endif
