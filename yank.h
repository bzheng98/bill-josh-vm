#ifndef YANK_H
#define YANK_H

#include "writeRegisterCommand.h"
#include "range.h"

class Yank: public WriteRegisterCommand {
  public:
    Yank(Vm *vm, FileManager *fm, RegisterManager *rm):
        Command{vm,fm,rm},
        WriteRegisterCommand{vm, fm, rm} {}
    void update(const CommandInfo &c) override;
    void yankLines(int count);
    void yankRange(const Range &range);
};
#endif
