#ifndef DELETECOMMAND_H
#define DELETECOMMAND_H

#include "writeRegisterCommand.h"
#include "range.h"

class DeleteCommand: public WriteRegisterCommand {
  protected:
    void deleteRange(const Range &range);
  public:
    DeleteCommand(Vm *vm, FileManager *fm, RegisterManager *rm):
        Command{vm,fm,rm},
        WriteRegisterCommand{vm, fm, rm} {}
};
#endif
