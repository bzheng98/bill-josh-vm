#include "write.h"

void Write::update(const CommandInfo &c) {
    if (c.getCommandType() != CommandType::WRITE)
        return;
    save();
}
