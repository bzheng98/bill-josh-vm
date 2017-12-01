#include "commandInfo.h"

const std::map<std::string, CommandType> CommandInfo::mapping{
    {"i", CommandType::INSERT},
    {"a", CommandType::APPEND},
    {"I", CommandType::PREPEND},
    {"o", CommandType::NEWLINE_BELOW},
    {"O", CommandType::NEWLINE_ABOVE},
    {"A", CommandType::APPEND_TO_LINE},
    {"R", CommandType::ENTER_REPLACE_MODE},
    {"h", CommandType::LEFT},
    {"j", CommandType::DOWN},
    {"k", CommandType::UP},
    {"l", CommandType::RIGHT},
    {":w", CommandType::WRITE},
    {":wq", CommandType::WRITEQUIT},
    {":q", CommandType::QUIT},
    {"u", CommandType::UNDO},
    {"d", CommandType::DELETE},
    {"y", CommandType::YANK},
    {"p", CommandType::PASTE}
};

const std::set<char> CommandInfo::motionCommands{
};

bool CommandInfo::isCommand(const std::string &s) {
    return mapping.find(s) != mapping.end();
}

CommandType CommandInfo::getCommandType(const std::string &s) {
    return mapping.at(s);
}

bool CommandInfo::isMotionCommand(char c) {
    return motionCommands.find(c) != motionCommands.end();
}
