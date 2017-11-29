#include "writequit.h"

void WriteQuit::update(const CommandInfo &c) {
    if (c.getCommandType() != CommandType::WRITEQUIT)
        return;
    save();
    quit();
}
