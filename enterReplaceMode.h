#ifndef ENTERREPLACEMODE_H
#define ENTERREPLACEMODE_H

#include "insertCommand.h"

class EnterReplaceMode: public InsertCommand {
  public:
    EnterReplaceMode(Vm *vm, FileManager *fm, RegisterManager *rm):
        Command{vm,fm,rm},
        InsertCommand{vm, fm, rm} {}
    void update(const CommandInfo &c) override;
    void doReplaceMode(int count);
};
#endif
