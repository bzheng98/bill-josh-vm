#include "up.h"

void Up::update(const CommandInfo &c) {
    moveCursor(0, -c.getCount());
}
