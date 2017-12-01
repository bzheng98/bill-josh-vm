#include "writeRegisterCommand.h"

void WriteRegisterCommand::writeToRegister(const std::string &s) {
    registerManager->writeRegister('"', s);
}
