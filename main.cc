#include "vm.h"
#include <string>
#include "left.h"
#include "right.h"
#include "up.h"
#include "down.h"

int main(int argc, char *argv[]) {
    if (argc == 1){
        //Vm myVim;
        //myVim.run();
    }
    else {
        Vm myVim{argv[1]};
        myVim.runVm();
    }
}
