#include "controller.h"

CommandInfo Controller::getCommand() {
    return commandType();
}

char Controller::getChar() {
    return readChar();
}
