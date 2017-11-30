#ifndef INSERT_H
#define INSERT_H

#include "insertMode.h"

class Insert: public InsertMode {
  public:
    Insert(Vm *vm, FileManager *fm, RegisterManager *rm):
        Command{vm,fm,rm},
        InsertMode{vm, fm, rm} {}
    void update(const CommandInfo &c) override;
};

#endif
