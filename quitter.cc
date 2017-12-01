#include "quitter.h"
#include "vm.h"

void Quitter::quit() {
    vm->quit();
}
