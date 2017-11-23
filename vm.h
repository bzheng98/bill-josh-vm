#ifndef VM_H
#define VM_H
#include <string>

class Vm: public Model, public Subject {
    void NotifyObservers();
  public:
    Vm(const string &fileName);
    void runVm();
    void runInsertMode();
    void addFootprint();
    void popFootprint();
    Footprint getLastFootprint();
    Command getPrevCommand();
}
#endif
