#include "paste.h"
#include "fileManager.h"
#include "registerManager.h"

void Paste::update(const CommandInfo &c) {
    if (c.getCommandType() == PASTE_AFTER) paste(c.getCount(), true);
    else if (c.getCommandType() == PASTE_BEFORE) paste(c.getCount(), false);
}

void Paste::paste(int count, bool after) {
    Position ogPos = fileManager->getCursorPosition();
    Position pos = ogPos;
    if (after)
        pos.setCol(pos.getCol()+1);
    const std::string &s = registerManager->readRegister('"');
    if (!s.length()) return;
    if (s.back() == '\n') { // linewise
        if (after)
            pos.setLine(pos.getLine()+1);
        pos.setCol(0);
    }
    fileManager->insertText(s,pos,count);
    createInsertFootprint(pos, fileManager->getCursorPosition(), ogPos);
    if (s.back() == '\n')
        fileManager->setCursorPosition(pos);
    else
        fileManager->leaveInsertMode();
}
