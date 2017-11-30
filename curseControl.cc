#include "curseControl.h"
#include <iostream>
#include "keys.h"

CurseKeyboard::CurseKeyboard(): mapping{
    {"i", CommandType::INSERT},
    {"a", CommandType::APPEND},
    {"I", CommandType::PREPEND},
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
    caller->log("getCommand: ");
    caller->log(ch);
    while (ch <= '9' && ch >= '0') {
        count = count * 10 + (ch - '0');
        ch = readChar();
        caller->log("getCommand: ");
        caller->log(ch);
    }
    if(count == 0) count = 1;
    std::string s;
    if (ch == ':') {
        while(!is_enter(ch)) {
            if (is_backspace(ch)) {
                s.erase(s.length()-1);
                if (!s.length()) {
                    caller->updateViewBottomTexts(s);
                    return commandType(caller);
                }
            }
            else s += ch;
            caller->updateViewBottomTexts(s);
            ch = readChar();
            caller->log("getCommand: ");
            caller->log(ch);
        }
    }
    else s = std::string(1, ch);
    if (mapping.find(s) == mapping.end()) return commandType(caller);
    return CommandInfo(mapping.at(s), count);
}

int CurseKeyboard::readChar() {
    return getch();
}
