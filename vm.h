#ifndef VM_H
#define VM_H
#include "commandType.h"
#include "model.h"
#include "subject.h"
#include "commandInfo.h"
#include "footprint.h"
#include "fileManager.h"
#include "registerManager.h"
#include "position.h"
#include <string>
#include <vector>

class MotionCommand;

class Vm: public Model, public Subject {
    bool running;
    FileManager fileManager;
    RegisterManager registerManager;
    std::vector<std::unique_ptr<Footprint> > footprints;
    size_t offset;
    size_t numLines;
    std::vector<MotionCommand *> motionCommands;
    int lastFootprint = 0;
    std::string lastSearch;
    bool searchForward;
    int nextSearch = 0;
  public:
    Vm(const std::string &fileName);
    void runVm();
    std::string runInsertMode(std::string &inserted, bool replace = false);
    void addFootprint(std::unique_ptr<Footprint> &&f);
    void popLastFootprint();
    Footprint &getLastFootprint();
    CommandInfo getPrevCommand();
    void quit();
    bool hasFootprint();
    Range getMotion(const CommandInfo &c);
	Position getViewCursor();
    bool isWritten();
    void write(std::string fileName);
    void storeLastSearch(const std::string &s, bool forward);
    const std::string &getLastSearch();
    bool getLastSearchDir();
    void nextSearchUsed(int count);
};
#endif
