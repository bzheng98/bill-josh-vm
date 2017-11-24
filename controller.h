#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "commandType.h"
#include <string>

class Controller {
    virtual CommandType commandType() = 0;
    virtual char readChar() = 0;
  public:
    CommandType getCommand();
    char getChar();
    virtual ~Controller() = default;
};
#endif
