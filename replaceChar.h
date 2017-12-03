#ifndef REPLACECHAR_H
#define REPLACECHAR_H 

#include "insertCommand.h"

class ReplaceChar: public InsertCommand {
  public:
    ReplaceChar(Vm *vm, FileManager *fm, RegisterManager *rm):
        Command{vm,fm,rm},
        InsertCommand{vm, fm, rm} {}
    void update(const CommandInfo &c) override;
};
#endif
