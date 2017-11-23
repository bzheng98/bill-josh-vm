#ifndef COMMAND_H
#define COMMAND_H
#include "vm.h"
#include "filemanager.h"
#include "registermanager.h"
#include "observer.h"

class Command: public Observer {
    Vm *vm;
    FileManager *fileManager;
    RegisterManager *registerManager;
  protected:
    Command(Vm *vm, FileManager *fileManager, RegisterManager *registerManager): vm{vm}, fileManager{fileManager}, registerManager{registerManager} {}
}
#endif
