#ifndef APPENDTOLINE_H
#define APPENDTOLINE_H

#include "insertMode.h"

class AppendToLine: public InsertMode {
  public:
    AppendToLine(Vm *vm, FileManager *fm, RegisterManager *rm): InsertMode{vm, fm, rm} {}
    void update(const CommandInfo &c) override;
};

#endif
