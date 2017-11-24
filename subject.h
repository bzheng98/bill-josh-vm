#ifndef SUBJECT_H
#define SUBJECT_H
#include "observer.h"
#include "commandInfo.h"
#include <vector>
#include <memory>

class Subject {
    std::vector<std::unique_ptr<Observer>> observers;
  protected:
    void notifyObservers(const CommandInfo &c);
};
#endif
