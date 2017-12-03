#include "replaceChar.h"
#include <string>
#include "vm.h"
#include "fileManager.h"
#include "keys.h"
#include "range.h"

void ReplaceChar::update(const CommandInfo &c) {
    if (c.getCommandType() != REPLACE_CHAR) return;
    int ch = vm->getChar();
    if (is_escape(ch) || is_enter(ch)) return;
    if (fileManager->getCurrentLineLength() - fileManager->getCursorPosition().getCol() < c.getCount()) return;

    Position p = fileManager->getCursorPosition();
    p.setCol(p.getCol()+c.getCount());
    std::string deleted = fileManager->deleteText(Range{fileManager->getCursorPosition(),p});
    for (int i = 0; i < c.getCount(); ++i)
        fileManager->insertChar(ch);
    p.setCol(p.getCol()-c.getCount());
    createReplaceFootprint(p, fileManager->getCursorPosition(), deleted);
    fileManager->leaveInsertMode();
}
