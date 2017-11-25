#include "right.h"

void Right::update(const CommandInfo &c) {
    moveCursor(c.getCount(), 0);
}
