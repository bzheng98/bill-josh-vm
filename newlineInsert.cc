#include "newlineInsert.h"
#include "fileManager.h"

void NewlineInsert::update(const CommandInfo &c) {
    bool above;
    auto cType = c.getCommandType();
    if (cType == NEWLINE_BELOW) above = false;
    else if (cType == NEWLINE_ABOVE) above = true;
    else return;
    fileManager->createAndGoToNewLine(above);
    doInsertMode(c.getCount());
}
