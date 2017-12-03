#include "lineJump.h"
#include "fileManager.h"

bool LineJump::checkCommand(const CommandInfo &c) {
    return c.getCommandType() == LINE_JUMP;
}

Position LineJump::getMotionResult(const CommandInfo &c) {
    return fileManager->cursor.getLine(c.getCount());
}

bool LineJump::isLinewise() {
    return true;
}
