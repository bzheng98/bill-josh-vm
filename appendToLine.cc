#include "appendToLine.h"

void AppendToLine::update(const CommandInfo &c) {
    if (c.getCommandType() != APPEND_TO_LINE) return;
    fileManager->goToEndOfLine(true);
    doInsertMode(c.getCount());
}
