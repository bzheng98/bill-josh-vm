#include "lineEnd.h"
#include "fileManager.h"

bool LineEnd::checkCommand(const CommandInfo &c) {
    return c.getCommandType() == LINE_END;
}

Position LineEnd::getMotionResult(const CommandInfo &c) {
    return fileManager->cursor.getLineEnd(c.getCount());
}

bool LineEnd::isLinewise() {
    return false;
}
