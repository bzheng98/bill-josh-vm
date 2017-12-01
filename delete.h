#ifndef DELETE_H
#define DELETE_H

#include "deleteCommand.h"

class Delete: public DeleteCommand {
  public:
    Delete(Vm *vm, FileManager *fm, RegisterManager *rm):
        Command{vm,fm,rm},
        DeleteCommand{vm, fm, rm} {}
    void update(const CommandInfo &c) override;
    void deleteLines(int count);
};
#endif
