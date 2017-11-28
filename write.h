#ifndef WRITE_H
#define WRITE_H

#include "writer.h"

class Write: public Writer {
  public:
    Write(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        Writer{vm, fileManager, registerManager} {}
    void update(const CommandInfo &c) override;
};
#endif
