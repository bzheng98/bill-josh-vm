#include "curseControl.h"
#include <string>

CurseKeyboard::CurseKeyboard() {
    //set up mapping here
}

CommandInfo CurseKeyboard::commandType() {
    //parsing and stuff
}

char CurseKeyboard::readChar() {
    return getch();
}
