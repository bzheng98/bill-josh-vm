#include "undo.h"

void Undo::update(const CommandInfo &c) {
    if (c.getCommandType() != UNDO) return;
    if (!vm->hasFootprint()) return;
    vm->getLastFootprint().undo(*fileManager);
    vm->popLastFootprint();
}
