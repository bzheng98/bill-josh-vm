#ifndef OBSERVER_H
#define OBSERVER_H
#include "commandInfo.h"

class Observer {
  public:
    virtual void update(CommandInfo c) = 0;
    virtual ~Observer() {}
};
#endif
