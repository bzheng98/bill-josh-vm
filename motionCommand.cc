#include "motionCommand.h"
#include "fileManager.h"

bool MotionCommand::checkCommand(const CommandInfo &c) {
    throw;
}

Position MotionCommand::getMotionResult(const CommandInfo &c) {
    throw;
}

bool MotionCommand::isLinewise() {
    throw;
}

void MotionCommand::update(const CommandInfo &c) {
    if (!checkCommand(c)) return;
    Position p = getMotionResult(c);
    if (p.getLine() == -1) return; // i.e. "f" command received escape`
    fileManager->setCursorPosition(p, !isLinewise(), false);
}
