#ifndef NEXTSEARCH_H
#define NEXTSEARCH_H

#include "command.h"

class NextSearch: public Command {
  public:
    NextSearch(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Command{vm, fileManager, registerManager} {}
    void update(const CommandInfo &c) override;
};
#endif
