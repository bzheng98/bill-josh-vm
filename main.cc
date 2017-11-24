#include "vm.h"
#include <string>

int main() {
    Vm myVim{"test.txt"};
    myVim.runVm();
}
