#ifndef COMMANDINFO_H
#define COMMANDINFO_H
#include "commandType.h"

class CommandInfo {
    CommandType commandType;
    int count;
  public:
    CommandType getCommandType() const { return commandType; }
    int getCount() const { return count; }
};
#endif
