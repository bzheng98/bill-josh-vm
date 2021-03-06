#include "nextSearch.h"
#include "vm.h"

void NextSearch::update(const CommandInfo &c) {
    bool next;
    if (c.getCommandType() == NEXT_SEARCH) next = true;
    else if (c.getCommandType() == PREV_SEARCH) next = false;
    else return;
    std::string lastSearch = vm->getLastSearch();
    if (!lastSearch.length()) return;
    bool dir = vm->getLastSearchDir();
    dir ^= next;
    vm->ungetChar(10);
    for (int i = lastSearch.length()-1; i >= 0; --i) {
        vm->ungetChar(lastSearch[i]);
    }
    if (!dir) vm->ungetChar('/');
    else vm->ungetChar('?');
    int count = c.getCount();
    if (count > 1) {
        std::string t = std::to_string(count);
        for (int i = t.length()-1; i >= 0; --i) {
            vm->ungetChar(t[i]);
        }
    }
    vm->nextSearchUsed(count);
}
