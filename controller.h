#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "commandInfo.h"
#include <string>

class Controller {
    virtual CommandInfo commandType() = 0;
    virtual char readChar() = 0;
  public:
    CommandInfo getCommand();
    char getChar();
    virtual ~Controller() = default;
};
#endif
