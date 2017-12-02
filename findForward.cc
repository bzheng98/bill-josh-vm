#include "findForward.h"
#include "fileManager.h"
#include "vm.h"
#include "keys.h"

bool FindForward::checkCommand(const CommandInfo &c) {
    return c.getCommandType() == FIND_FORWARD;
}

Position FindForward::getMotionResult(const CommandInfo &c) {
    int findChar = vm->getChar();
    if (is_escape(findChar)) return Position{-1,-1};
    return fileManager->cursor.findForward(findChar, c.getCount());
}

bool FindForward::isLinewise() {
    return false;
}
