#include "insert.h"

void Insert::update(const CommandInfo &c) {
    if (c.getCommandType() != INSERT) return;
    doInsertMode();

}
