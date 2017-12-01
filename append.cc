#include "append.h"
#include "fileManager.h"

void Append::update(const CommandInfo &c) {
    if (c.getCommandType() != APPEND) return;
    fileManager->moveCursorPosition(1,0,true);
    doInsertMode(c.getCount(), fileManager->getCursorPosition());
}
