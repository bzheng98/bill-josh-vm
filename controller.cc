#include "controller.h"

CommandInfo Controller::getCommand(Model *caller) {
    return commandType(caller);
}

int Controller::getChar() {
    return readChar();
}

void Controller::ungetChar(int c) {
    putChar(c);
}
