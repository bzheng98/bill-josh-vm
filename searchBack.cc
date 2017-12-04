#include "searchBack.h"
#include "fileManager.h"
#include "vm.h"
#include "keys.h"

bool SearchBack::checkCommand(const CommandInfo &c) {
    return c.getCommandType() == SEARCH_BACK;
}

Position SearchBack::getMotionResult(const CommandInfo &c) {
    int in = vm->getChar();
    std::string s;
    while(!is_enter(in)) {
        s += in;
        in = vm->getChar();
        vm->log(in);
    }
    if (!s.length()) {
        s = vm->getLastSearch();
    }
    vm->storeLastSearch(s, false);
    return fileManager->cursor.searchBack(s, c.getCount());
}

bool SearchBack::isLinewise() {
    return false;
}
