#include "registermanager.h"
#include <map>
#include <string>

const string RegisterManager::readRegister(char c) {
    return registers.at(c);
}
void RegisterManager::writeRegister(char c, string s) {
    registers[c] = s;
}
