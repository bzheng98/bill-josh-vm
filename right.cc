#include "right.h"
#include <iostream>
void Right::update(const CommandInfo &c) {
    if(c.getCommandType() == RIGHT) {
        moveCursor(c.getCount(), 0);
    }
}
