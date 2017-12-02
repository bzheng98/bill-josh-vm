#ifndef PASTE_H 
#define PASTE_H 

#include "insertCommand.h"

class Paste: public InsertCommand {
    void paste(int count, bool after);
  public:
    Paste(Vm *vm, FileManager *fm, RegisterManager *rm):
        Command{vm,fm,rm},
        InsertCommand{vm, fm, rm} {}
    void update(const CommandInfo &c) override;
};
#endif
