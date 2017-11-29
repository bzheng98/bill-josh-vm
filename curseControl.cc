#include "curseControl.h"
#include <iostream>
#include "keys.h"

CurseKeyboard::CurseKeyboard(): mapping{
    {"i", CommandType::INSERT},
    {"h", CommandType::LEFT},
    {"j", CommandType::DOWN},
    {"k", CommandType::UP},
    {"l", CommandType::RIGHT},
    {":w", CommandType::WRITE},
    {":wq", CommandType::WRITEQUIT},
    {":q", CommandType::QUIT}} {
}

CommandInfo CurseKeyboard::commandType(Model *caller) {
    //get the count
    int count = 0, ch = readChar();
    while (ch <= '9' && ch >= '0') {
        count = count * 10 + (ch - '0');
        ch = readChar();
    }
    if(count == 0)count = 1;
    if(is_escape(ch))throw;
    std::string s;
    if (ch == ':') {
        while(!is_enter(ch)) {
            if (is_backspace(ch)) s.erase(s.length()-1);
            else s += ch;
            caller->updateViewBottomTexts(s);
            ch = readChar();
        }
    }
    else s = std::string(1, ch);
    if (mapping.find(s) == mapping.end()) return commandType(caller);
    return CommandInfo(mapping.at(s), count);
}

int CurseKeyboard::readChar() {
    return getch();
}
