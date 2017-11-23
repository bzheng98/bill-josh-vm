#ifndef OBSERVER_H
#define OBSERVER_H
#include "command.h"

class Observer {
  public:
    virtual void update(Command c) = 0;
}
#endif
