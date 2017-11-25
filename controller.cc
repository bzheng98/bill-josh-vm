#include "controller.h"

CommandInfo Controller::getCommand() {
    return commandType();
}

int Controller::getChar() {
    return readChar();
}
