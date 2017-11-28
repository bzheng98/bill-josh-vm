#include "curseControl.h"
#include <string>

CurseKeyboard::CurseKeyboard(): mapping{
    {"i", CommandType::INSERT},
    {"h", CommandType::LEFT},
    {"j", CommandType::DOWN},
    {"k", CommandType::UP},
    {"l", CommandType::RIGHT}} {
}

CommandInfo CurseKeyboard::commandType() {
    //get the count
    int count = 0, ch;
    while(true) {
        ch = readChar();
        if(ch <= '9' && ch >= '0') {
            count = count * 10 + (ch - '0');
        }
        else {
            //ungetch(ch);
            break;
        }
    }
    if(count == 0)count = 1;
    if(ch == 27)throw;
    std::string s = std::string(1, ch);
    if (mapping.find(s) == mapping.end()) return commandType();
    return CommandInfo(mapping.at(std::string(1, ch)), count);
}

int CurseKeyboard::readChar() {
    return getch();
}
