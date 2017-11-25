#include "left.h"

void Left::update(const CommandInfo &c) {
    moveCursor(-c.getCount(), 0);
}
