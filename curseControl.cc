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
    return CommandInfo(mapping[std::string(1, ch)], count);
}

int CurseKeyboard::readChar() {
    return getch();
}
