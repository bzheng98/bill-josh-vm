#ifndef WRITEQUIT_H
#define WRITEQUIT_H

#include "writer.h"
#include "quitter.h"

class WriteQuit: public Writer, public Quitter {
  public:
    WriteQuit(Vm *vm, FileManager *fileManager, RegisterManager *registerManager):
        FileCommand{vm, fileManager, registerManager},
        Writer{vm, fileManager, registerManager},
        Quitter{vm, fileManager, registerManager} {}
    void update(const CommandInfo &c) override;
};
#endif
