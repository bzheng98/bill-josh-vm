#include "motionCommand.h"
#include "fileManager.h"

bool MotionCommand::checkCommand(const CommandInfo &c) {
    throw;
}

Position MotionCommand::getMotionResult(const CommandInfo &c) {
    throw;
}

bool MotionCommand::isChangeCol() {
    throw;
}

void MotionCommand::update(const CommandInfo &c) {
    if (!checkCommand(c)) return;
    Position p = getMotionResult(c);
    fileManager->setCursorPosition(p, isChangeCol(), false);
}
