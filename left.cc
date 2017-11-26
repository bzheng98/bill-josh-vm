#include "left.h"

void Left::update(const CommandInfo &c) {
    if(c.getCommandType() == LEFT) {
        moveCursor(-c.getCount(), 0);
    }
}
