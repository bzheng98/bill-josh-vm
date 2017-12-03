#include "curseControl.h"
#include <iostream>
#include "keys.h"

CommandInfo CurseKeyboard::commandType(Model *caller) {
    //get the count
    int count = 0, ch = readChar();
    caller->log("getCommand: ");
    caller->log(ch);
    if (ch >= '1' && ch <= '9')
        while (ch <= '9' && ch >= '0') {
            count = count * 10 + (ch - '0');
            ch = readChar();
            caller->log("getCommand: ");
            caller->log(ch);
        }
    else count = 1;
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
        if (s.size()>1 && s[1] >= '0' && s[1] <= '9') {
            count = 0;
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] < '0' || s[i] > '9') return commandType(caller);
                count = count * 10 + s[i] - '0';
            }
            s = ":0";
        }
        caller->updateViewBottomTexts("");
    }
	else if(ch == 4) s = "^d";
	else if(ch == 21) s = "^u";
	else if(ch == 6) s = "^f";
	else if(ch == 2) s = "^b";
    else s = std::string(1, ch);
    if (!CommandInfo::isCommand(s)) return commandType(caller);
    return CommandInfo(CommandInfo::getCommandType(s), count);
}

int CurseKeyboard::readChar() {
    return getch();
}

void CurseKeyboard::putChar(int c) {
    ungetch(c);
}
