#include "writeRegisterCommand.h"
#include "registerManager.h"

void WriteRegisterCommand::writeToRegister(const std::string &s) {
    registerManager->writeRegister('"', s);
}
