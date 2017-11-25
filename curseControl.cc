#include "curseControl.h"
#include <string>

CurseKeyboard::CurseKeyboard() {
    //set up mapping here
    mapping["i"] = CommandType::INSERT;
    mapping["h"] = CommandType::LEFT;
    mapping["j"] = CommandType::DOWN;
    mapping["k"] = CommandType::UP;
    mapping["l"] = CommandType::RIGHT;
}

CommandInfo CurseKeyboard::commandType() {
    //no count for now
    char ch = readChar();
    int count = 1;
    return CommandInfo(mapping[std::string(1, ch)], count);
}

int CurseKeyboard::readChar() {
    return getch();
}
