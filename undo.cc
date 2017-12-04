#include "undo.h"
#include "vm.h"

void Undo::update(const CommandInfo &c) {
    if (c.getCommandType() != UNDO) return;
    if (!vm->hasFootprint()) return;
    bool b = vm->getLastFootprint().undo(*fileManager);
    vm->popLastFootprint();
    if (!b) {
        vm->getLastFootprint().undo(*fileManager);
        vm->popLastFootprint();
    }
}
