#include "insert.h"
#include "fileManager.h"

void Insert::update(const CommandInfo &c) {
    if (c.getCommandType() != INSERT) return;
    doInsertMode(c.getCount(), fileManager->getCursorPosition());
}
