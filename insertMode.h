#ifndef INSERTMODE_H
#define INSERTMODE_H

#include "insertCommand.h"

class InsertMode: public InsertCommand {
  protected:
    InsertMode(Vm *vm, FileManager *fm, RegisterManager *rm): InsertCommand{vm, fm, rm} {}
    void doInsertMode();
};
#endif
