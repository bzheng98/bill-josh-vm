#ifndef CURSE_CONTROL_H
#define CURSE_CONTROL_H

#include "controller.h"
#include <map>
#include <string>
#include <ncurses.h>

class CurseKeyboard: public Controller {
    std::map<std::string, Action> mapping;
    CommandType() commandType() override;
    char readChar() override;
public:
    CurseKeyboard();
};
#endif
