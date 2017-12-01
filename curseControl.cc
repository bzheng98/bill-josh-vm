#include "curseControl.h"
#include <iostream>
#include "keys.h"

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
    if (!CommandInfo::isCommand(s)) return commandType(caller);
    return CommandInfo(CommandInfo::getCommandType(s), count);
}

int CurseKeyboard::readChar() {
    return getch();
}
