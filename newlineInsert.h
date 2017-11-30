#ifndef NEWLINEINSERT_H
#define NEWLINEINSERT_H

#include "insertMode.h"

class NewlineInsert: public InsertMode {
  public:
    NewlineInsert(Vm *vm, FileManager *fm, RegisterManager *rm):
        Command{vm,fm,rm},
        InsertMode{vm, fm, rm} {}
    void update(const CommandInfo &c) override;
};

#endif
