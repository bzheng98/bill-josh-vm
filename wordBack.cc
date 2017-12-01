#include "wordBack.h"
#include "fileManager.h"

bool WordBack::checkCommand(const CommandInfo &c) {
    return c.getCommandType() == WORD_BACK;
}

Position WordBack::getMotionResult(const CommandInfo &c) {
    return fileManager->cursor.getBackWord();
}

bool WordBack::isChangeCol() {
    return true;
}
