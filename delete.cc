#include "delete.h"
#include "keys.h"
#include "motionCommand.h"
#include "range.h"
#include "commandInfo.h"
#include "vm.h"

void Delete::update(const CommandInfo &c) {
    if (c.getCommandType() != DELETE) return;
    int motionChar = vm->getChar();
    if (motionChar == 'd') {
        deleteLines(c.getCount());
        return;
    }
    vm->log("Motion char:");
    vm->log(motionChar);
    if (is_escape(motionChar)) return;
    vm->ungetChar(motionChar);
    CommandInfo motion = vm->getCommand(vm);
    if (!CommandInfo::isMotionCommand(motion)) return;
    Range range = vm->getMotion(motion);
    deleteRange(range);
}

void Delete::deleteLines(int count) {
    Position begin = fileManager->getCursorPosition();
    begin.setCol(0);
    Position end = begin;
    end.setLine(begin.getLine()+count);
    deleteRange(Range{begin,end});
}
