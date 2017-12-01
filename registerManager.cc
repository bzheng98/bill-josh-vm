#include "registerManager.h"

const std::string &RegisterManager::readRegister(char c) const {
    return registers.at(c);
}
void RegisterManager::writeRegister(char c, const std::string &s) {
    registers[c] = s;
}
