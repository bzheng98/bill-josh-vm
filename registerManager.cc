#include "registerManager.h"

const std::string RegisterManager::readRegister(char c) {
    return registers.at(c);
}
void RegisterManager::writeRegister(char c, std::string s) {
    registers[c] = s;
}
