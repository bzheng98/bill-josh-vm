#include "findBack.h"
#include "fileManager.h"
#include "vm.h"
#include "keys.h"

bool FindBack::checkCommand(const CommandInfo &c) {
    return c.getCommandType() == FIND_BACK;
}

Position FindBack::getMotionResult(const CommandInfo &c) {
    int findChar = vm->getChar();
    if (is_escape(findChar)) return Position{-1,-1};
    return fileManager->cursor.findBack(findChar, c.getCount());
}

bool FindBack::isLinewise() {
    return false;
}
