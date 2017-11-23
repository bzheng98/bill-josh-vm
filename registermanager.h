#ifndef REGISTERMANAGER_H
#define REGISTERMANAGER_H
#include <map>
#include <string>
class RegisterManager{
    std::map<char, string> registers;
  public:
    const string readRegister(char c);
    void writeRegister(char c, string s);
}
#endif
