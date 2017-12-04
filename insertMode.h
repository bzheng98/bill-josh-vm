#ifndef INSERTMODE_H
#define INSERTMODE_H

#include "insertCommand.h"

class InsertMode: public InsertCommand {
  protected:
    void doInsertMode(int count, Position originalCursor, bool newline = false, bool forceFootprint = false);
  public:
    InsertMode(Vm *vm, FileManager *fm, RegisterManager *rm):
        Command{vm,fm,rm},
        InsertCommand{vm, fm, rm} {}
};
#endif
