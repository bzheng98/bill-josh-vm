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
    {"^u", CommandType::SCROLLUP},
    {"^d", CommandType::SCROLLDOWN},
	{"^f", CommandType::SCROLLFORWARD},
	{"^b", CommandType::SCROLLBACKWARD},
    {"y", CommandType::YANK},
    {"p", CommandType::PASTE_AFTER},
    {"w", CommandType::WORD_FORWARD},
    {"b", CommandType::WORD_BACK},
    {"f", CommandType::FIND_FORWARD},
    {"F", CommandType::FIND_BACK},
    {"P", CommandType::PASTE_BEFORE},
    {"0", CommandType::LINE_BEGIN},
    {"$", CommandType::LINE_END},
    {":0", CommandType::LINE_JUMP},
    {"%", CommandType::JUMP_TO_MATCH},
    {"/", CommandType::SEARCH_FORWARD},
    {"?", CommandType::SEARCH_BACK},
    {"r", CommandType::REPLACE_CHAR},
    {"c", CommandType::REPLACE_MOTION},
    {":q!", CommandType::FORCE_QUIT},
    {"n", CommandType::NEXT_SEARCH},
    {"N", CommandType::PREV_SEARCH}
};

const std::set<CommandType> CommandInfo::motionCommands{
    CommandType::UP,
    CommandType::DOWN,
    CommandType::LEFT,
    CommandType::RIGHT,
    CommandType::WORD_FORWARD,
    CommandType::WORD_BACK,
    CommandType::FIND_FORWARD,
    CommandType::FIND_BACK,
    CommandType::LINE_BEGIN,
    CommandType::LINE_END,
    CommandType::LINE_JUMP,
    CommandType::JUMP_TO_MATCH,
    CommandType::SEARCH_FORWARD,
    CommandType::SEARCH_BACK
};

bool CommandInfo::isCommand(const std::string &s) {
    return mapping.find(s) != mapping.end();
}

CommandType CommandInfo::getCommandType(const std::string &s) {
    return mapping.at(s);
}

bool CommandInfo::isMotionCommand(const CommandInfo &c) {
    return motionCommands.find(c.getCommandType()) != motionCommands.end();
}
