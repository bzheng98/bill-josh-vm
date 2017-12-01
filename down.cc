#include "down.h"
#include "fileManager.h"

bool Down::checkCommand(const CommandInfo &c) {
    return c.getCommandType() == DOWN;
}

Position Down::getMotionResult(const CommandInfo &c) {
    return fileManager->cursor.getDown(c.getCount());
}

bool Down::isLinewise() {
    return true;
}
