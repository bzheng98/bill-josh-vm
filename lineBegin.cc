#include "lineBegin.h"
#include "fileManager.h"

bool LineBegin::checkCommand(const CommandInfo &c) {
    return c.getCommandType() == LINE_BEGIN;
}

Position LineBegin::getMotionResult(const CommandInfo &c) {
    return fileManager->cursor.getLineBegin();
}

bool LineBegin::isLinewise() {
    return false;
}
