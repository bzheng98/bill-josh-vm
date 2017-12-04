#include "quit.h"

void Quit::update(const CommandInfo &c) {
    if (c.getCommandType() != CommandType::QUIT)
        return;
    quit(false);
}
