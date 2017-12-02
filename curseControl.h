#ifndef CURSE_CONTROL_H
#define CURSE_CONTROL_H

#include "controller.h"
#include "commandInfo.h"
#include "commandType.h"
#include "model.h"
#include <string>
#include <ncurses.h>

class CurseKeyboard: public Controller {
    CommandInfo commandType(Model *caller) override;
    int readChar() override;
    void putChar(int c) override;
  public:
    CurseKeyboard() = default;
};
#endif
