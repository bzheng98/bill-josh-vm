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
    if (is_escape(motionChar) || !CommandInfo::isMotionCommand((char)motionChar)) return;
    Range motion = vm->getMotion((char)motionChar);
}

void Delete::deleteLines(int count) {
    Position begin = fileManager->getCursorPosition();
    begin.setCol(0);
    Position end = begin;
    end.setLine(begin.getLine()+count);
    deleteRange(Range{begin,end});
}
