#include "replaceMotion.h"
#include "keys.h"
#include "motionCommand.h"
#include "range.h"
#include "commandInfo.h"
#include "vm.h"

void ReplaceMotion::update(const CommandInfo &c) {
    if (c.getCommandType() != REPLACE_MOTION) return;
    int motionChar = vm->getChar();
    if (motionChar == 'c') {
        replaceLines(c.getCount());
        return;
    }
    if (is_escape(motionChar)) return;
    vm->ungetChar(motionChar);
    CommandInfo motion = vm->getCommand(vm);
    if (!CommandInfo::isMotionCommand(motion)) return;
    Range range = vm->getMotion(motion);
    replaceRange(range);
}

void ReplaceMotion::replaceLines(int count) {
    Position begin = fileManager->getCursorPosition();
    begin.setCol(0);
    Position end = begin;
    end.setLine(begin.getLine()+count);
    replaceRange(Range{begin,end});
}

void ReplaceMotion::replaceRange(const Range &r) {
    bool linewise = r.getStart().getCol() == 0 && r.getEnd().getCol() == 0;
    Position p = fileManager->getCursorPosition();
    deleteRange(r);
    if (linewise) {
        fileManager->createAndGoToNewLine(true);
        doInsertMode(1, p, true, true);
    }
    else {
        doInsertMode(1, p, false, true);
    }
}
