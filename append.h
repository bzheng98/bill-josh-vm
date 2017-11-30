#ifndef APPEND_H
#define APPEND_H

#include "insertMode.h"

class Append: public InsertMode {
  public:
    Append(Vm *vm, FileManager *fm, RegisterManager *rm): InsertMode{vm, fm, rm} {}
    void update(const CommandInfo &c) override;
};

#endif
