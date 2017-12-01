#include "wordForward.h"
#include "fileManager.h"

bool WordForward::checkCommand(const CommandInfo &c) {
    return c.getCommandType() == WORD_FORWARD;
}

Position WordForward::getMotionResult(const CommandInfo &c) {
    return fileManager->cursor.getForwardWord();
}

bool WordForward::isChangeCol() {
    return true;
}
