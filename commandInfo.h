#ifndef COMMANDINFO_H
#define COMMANDINFO_H
#include "commandType.h"
#include <string>
#include <map>
#include <set>

class CommandInfo {
    static const std::map<std::string, CommandType> mapping;
    static const std::set<CommandType> motionCommands;
    CommandType commandType;
    int count;
  public:
    CommandInfo(CommandType commandType, int count) : commandType{commandType}, count{count} {}
    CommandType getCommandType() const { return commandType; }
    int getCount() const { return count; }
    static bool isCommand(const std::string &s);
    static CommandType getCommandType(const std::string &s);
    static bool isMotionCommand(const CommandInfo &c);
};
#endif
