#include "vm.h"
#include <string>
#include "left.h"
#include "right.h"
#include "up.h"
#include "down.h"

int main() {
    Vm myVim{"test.cc"};

    myVim.runVm();
}
