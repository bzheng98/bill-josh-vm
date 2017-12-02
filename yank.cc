#include "yank.h"
#include "keys.h"
#include "motionCommand.h"
#include "range.h"
#include "commandInfo.h"
#include "vm.h"

void Yank::update(const CommandInfo &c) {
    if (c.getCommandType() != YANK) return;
    int motionChar = vm->getChar();
    if (motionChar == 'y') {
        yankLines(c.getCount());
        return;
    }
    if (is_escape(motionChar)) return;
    vm->ungetChar(motionChar);
    CommandInfo motion = vm->getCommand(vm);
    if (!CommandInfo::isMotionCommand(motion)) return;
    Range range = vm->getMotion(motion);
}

void Yank::yankLines(int count) {
    Position begin = fileManager->getCursorPosition();
    begin.setCol(0);
    Position end = begin;
    end.setLine(begin.getLine()+count);
    yankRange(Range{begin,end});
}

void Yank::yankRange(const Range &range) {
    writeToRegister(fileManager->getText(range));
}
