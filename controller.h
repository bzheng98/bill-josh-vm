#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "commandInfo.h"
#include <string>

class Model;

class Controller {
    virtual CommandInfo commandType(Model *caller) = 0;
    virtual int readChar() = 0;
  public:
    CommandInfo getCommand(Model *caller);
    int getChar();
    virtual ~Controller() = default;
};
#endif
