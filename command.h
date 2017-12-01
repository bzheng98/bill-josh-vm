#ifndef COMMAND_H
#define COMMAND_H
#include "observer.h"

class Vm;
class FileManager;
class RegisterManager;

class Command: public Observer {
  protected:
    Vm *vm;
    FileManager *fileManager;
    RegisterManager *registerManager;
    Command(Vm *vm, FileManager *fileManager, RegisterManager *registerManager): vm{vm}, fileManager{fileManager}, registerManager{registerManager} {}
};
#endif
