#include "right.h"
#include "fileManager.h"

bool Right::checkCommand(const CommandInfo &c) {
    return c.getCommandType() == RIGHT;
}

Position Right::getMotionResult(const CommandInfo &c) {
    return fileManager->cursor.getRight(c.getCount());
}

bool Right::isLinewise() {
    return false;
}
