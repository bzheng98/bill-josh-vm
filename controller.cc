#include "controller.h"

CommandType Controller::getCommand() {
    return commandType();
}

char Controller::getChar() {
    return readChar();
}
