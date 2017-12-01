#include "paste.h"
#include "fileManager.h"
#include "registerManager.h"

void Paste::update(const CommandInfo &c) {
    if (c.getCommandType() != PASTE) return;
    paste(c.getCount());
}

void Paste::paste(int count) {
    Position pos = fileManager->getCursorPosition();
    Position ogPos = pos;
    const std::string &s = registerManager->readRegister('"');
    if (!s.length()) return;
    if (s.back() == '\n') { // linewise
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
