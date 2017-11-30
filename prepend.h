#ifndef PREPEND_H
#define PREPEND_H

#include "insertMode.h"

class Prepend: public InsertMode {
  public:
    Prepend(Vm *vm, FileManager *fm, RegisterManager *rm): InsertMode{vm, fm, rm} {}
    void update(const CommandInfo &c) override;
};

#endif
