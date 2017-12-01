#include "down.h"
#include "fileManager.h"

bool Down::checkCommand(const CommandInfo &c) {
    return c.getCommandType() == DOWN;
}

Position Down::getMotionResult(const CommandInfo &c) {
    return fileManager->cursor.getDown();
}

bool Down::isChangeCol() {
    return false;
}
