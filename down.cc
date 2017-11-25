#include "down.h"

void Down::update(const CommandInfo &c) {
    moveCursor(0, c.getCount());
}
