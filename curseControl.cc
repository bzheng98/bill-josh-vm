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
        if (s[1] == 'w' && (s[2] == ' ' || s.size() == 2)) {
            ungetch(10);
            for (int i = s.size()-1; i >= 3; --i) {
                ungetch(s[i]);
            }
            s = ":w";
        }
        else if (s[1] == 'w' && s[2] == 'q' && (s[3] == ' ' || s.size() == 3)) {
            ungetch(10);
            for (int i = s.size()-1; i >= 4; --i) {
                ungetch(s[i]);
            }
            s = ":wq";
        }
    }
    else if (ch == '/' || ch == '?') {
        std::string t = {ch};
        while (!is_enter(ch)) {
            if (is_backspace(ch)) {
                s.pop_back();
                if (!s.length()) {
                    caller->updateViewBottomTexts(s);
                    return commandType(caller);
                }
            }
            else s += ch;
            caller->updateViewBottomTexts(s);
            ch = readChar();
        }
        caller->updateViewBottomTexts("");
        ungetch(10);
        for (int i = s.length()-1; i >= 1; --i) {
            ungetch(s[i]);
        }
        s = t;
    }
    else if (ch == 'S') {
        ungetch('c');
        s = "c";
    }
    else if (ch == 's') {
        std::string t = std::to_string(count);
        ungetch('l');
        for (int i = t.size()-1; i >= 0; --i) {
            ungetch(t[i]);
        }
        s = "c";
    }
    else if (ch == 'x') {
        std::string t = std::to_string(count);
        ungetch('l');
        for (int i = t.size()-1; i >= 0; --i) {
            ungetch(t[i]);
        }
        s = "d";
    }
    else if (ch == 'X') {
        std::string t = std::to_string(count);
        ungetch('h');
        for (int i = t.size()-1; i >= 0; --i) {
            ungetch(t[i]);
        }
        s = "d";
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
    int c = getch();
    if (is_tab(c)) {
        ungetch(' ');
        ungetch(' ');
        ungetch(' ');
        c = ' ';
    }
    return c;
}

void CurseKeyboard::putChar(int c) {
    ungetch(c);
}
