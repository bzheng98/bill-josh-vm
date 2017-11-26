#ifndef VM_H
#define VM_H
#include "model.h"
#include "subject.h"
#include "commandInfo.h"
#include "footprint.h"
#include "fileManager.h"
#include "registerManager.h"
#include <string>

class Vm: public Model, public Subject {
    bool running, insertMode;
    FileManager fileManager;
    RegisterManager registerManager;
    size_t offset;
    size_t numLines;
  public:
    Vm(const std::string &fileName);
    void runVm();
    void runInsertMode();
    void addFootprint();
    void popFootprint();
    Footprint getLastFootprint();
    CommandInfo getPrevCommand();
};
#endif
