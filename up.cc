#include "up.h"
#include <iostream>
void Up::update(const CommandInfo &c) {
    if(c.getCommandType() == UP) {
        moveCursor(0, -c.getCount());
    }
}
