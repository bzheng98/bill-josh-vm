#include "quitter.h"
#include "vm.h"

void Quitter::quit(bool wrote) {
    if (wrote || vm->isWritten())
        vm->quit();
    else {
        vm->updateViewBottomTexts("E37: No write since last change (add ! to override)");
    }
}
