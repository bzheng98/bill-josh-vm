#include "prepend.h"
#include "fileManager.h"

void Prepend::update(const CommandInfo &c) {
    if (c.getCommandType() != PREPEND) return;
    Position p = fileManager->getCursorPosition();
    p.setCol(0);
    fileManager->setCursorPosition(p, true);
    doInsertMode(c.getCount());
}
