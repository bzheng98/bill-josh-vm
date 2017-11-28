#ifndef CURSE_CONTROL_H
#define CURSE_CONTROL_H

#include "controller.h"
#include "commandInfo.h"
#include "commandType.h"
#include "model.h"
#include <map>
#include <string>
#include <ncurses.h>

class CurseKeyboard: public Controller {
    const std::map<std::string, CommandType> mapping;
    CommandInfo commandType(Model *caller) override;
    int readChar() override;
  public:
    CurseKeyboard();
};
#endif
