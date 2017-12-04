#ifndef REPLACEMOTION_H
#define REPLACEMOTION_H

#include "deleteCommand.h"
#include "insertMode.h"
#include "range.h"

class ReplaceMotion:public InsertMode, public DeleteCommand {
    void replaceRange(const Range &r);
  public:
    ReplaceMotion(Vm *vm, FileManager *fm, RegisterManager *rm):
        Command{vm,fm,rm},
        InsertMode{vm,fm,rm},
        DeleteCommand{vm, fm, rm} {}
    void update(const CommandInfo &c) override;
    void replaceLines(int count);
};
#endif
