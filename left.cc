#include "left.h"
#include "fileManager.h"

bool Left::checkCommand(const CommandInfo &c) {
    return c.getCommandType() == LEFT;
}

Position Left::getMotionResult(const CommandInfo &c) {
    return fileManager->cursor.getLeft(c.getCount());
}

bool Left::isLinewise() {
    return false;
}
