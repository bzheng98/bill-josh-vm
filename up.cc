#include "up.h"
#include "fileManager.h"

bool Up::checkCommand(const CommandInfo &c) {
    return c.getCommandType() == UP;
}

Position Up::getMotionResult(const CommandInfo &c) {
    return fileManager->cursor.getUp(c.getCount());
}

bool Up::isLinewise() {
    return true;
}
