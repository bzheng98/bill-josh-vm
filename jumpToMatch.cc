#include "jumpToMatch.h"
#include "fileManager.h"

bool JumpToMatch::checkCommand(const CommandInfo &c) {
    return c.getCommandType() == JUMP_TO_MATCH;
}

Position JumpToMatch::getMotionResult(const CommandInfo &c) {
    return fileManager->cursor.getMatch();
}

bool JumpToMatch::isLinewise() {
    return true;
}
