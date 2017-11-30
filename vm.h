#ifndef VM_H
#define VM_H
#include "commandType.h"
#include "model.h"
#include "subject.h"
#include "commandInfo.h"
#include "footprint.h"
#include "fileManager.h"
#include "registerManager.h"
#include <string>
#include <vector>
#include <fstream>


class Vm: public Model, public Subject {
    bool running;
    FileManager fileManager;
    RegisterManager registerManager;
    std::vector<std::unique_ptr<Footprint> > footprints;
    size_t offset;
    size_t numLines;
  public:
    Vm(const std::string &fileName);
    void runVm();
    std::string runInsertMode(std::string &inserted, bool replace = false);
    void addFootprint(std::unique_ptr<Footprint> &&f);
    void popFootprint();
    Footprint getLastFootprint();
    CommandInfo getPrevCommand();
    void quit();
};
#endif
