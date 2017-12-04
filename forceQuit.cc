#include "forceQuit.h"

void ForceQuit::update(const CommandInfo &c) {
    if (c.getCommandType() != CommandType::FORCE_QUIT)
        return;
    quit(true);
}
