#ifndef COMMANDINFO_H
#define COMMANDINFO_H
#include "commandType.h"

class CommandInfo {
    CommandType commandType;
    int count;
  public:
    CommandInfo(CommandType commandType, int count) : commandType{commandType}, count{count} {}
    CommandType getCommandType() const { return commandType; }
    int getCount() const { return count; }
};
#endif
