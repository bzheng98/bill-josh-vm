#include "down.h"
#include <iostream>
void Down::update(const CommandInfo &c) {
    if(c.getCommandType() == DOWN) {
        //std::cout << "down\n";
        moveCursor(0, c.getCount());
    }
}
