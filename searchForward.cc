#include "searchForward.h"
#include "fileManager.h"
#include "vm.h"
#include "keys.h"

bool SearchForward::checkCommand(const CommandInfo &c) {
    return c.getCommandType() == SEARCH_FORWARD;
}

Position SearchForward::getMotionResult(const CommandInfo &c) {
    int in = vm->getChar();
    std::string s;
    while(!is_enter(in)) {
        s += in;
        in = vm->getChar();
        vm->log(in);
    }
    vm->log("SEARCH");
    vm->log(s);
    if (!s.length())
        s = vm->getLastSearch();
    vm->storeLastSearch(s, true);
    return fileManager->cursor.searchForward(s, c.getCount());
}

bool SearchForward::isLinewise() {
    return false;
}
