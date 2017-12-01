#ifndef REGISTERMANAGER_H
#define REGISTERMANAGER_H
#include <map>
#include <string>
class RegisterManager {
    std::map<char, std::string> registers;
  public:
    const std::string &readRegister(char c) const;
    void writeRegister(char c, const std::string &s);
};
#endif
