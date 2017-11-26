#ifndef COMMAND_H
#define COMMAND_H
#include "vm.h"
#include "fileManager.h"
#include "registerManager.h"
#include "commandType.h"
#include "observer.h"

enum CommandType;

class Command: public Observer {
  protected:
    Vm *vm;
    FileManager *fileManager;
    RegisterManager *registerManager;
    Command(Vm *vm, FileManager *fileManager, RegisterManager *registerManager): vm{vm}, fileManager{fileManager}, registerManager{registerManager} {}
};
#endif
