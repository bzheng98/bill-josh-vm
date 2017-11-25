#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "commandInfo.h"
#include <string>

class Controller {
    virtual CommandInfo commandType() = 0;
    virtual int readChar() = 0;
  public:
    CommandInfo getCommand();
    int getChar();
    virtual ~Controller() = default;
};
#endif
