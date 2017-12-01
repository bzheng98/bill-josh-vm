#include "enterReplaceMode.h"
#include "replaceFootprint.h"
#include <string>
#include "vm.h"
#include "fileManager.h"

void EnterReplaceMode::update(const CommandInfo &c) {
    if (c.getCommandType() != ENTER_REPLACE_MODE) return;
    doReplaceMode(c.getCount());
}

void EnterReplaceMode::doReplaceMode(int count) {
    Position startingPos = fileManager->getCursorPosition();
    std::string inserted;
    std::string replaced = vm->runInsertMode(inserted, true);
    if (count > 1)
        replaced += fileManager->replaceText(inserted, fileManager->getCursorPosition(), count-1);
    vm->addFootprint(std::unique_ptr<Footprint>(new ReplaceFootprint(startingPos, fileManager->getCursorPosition(), replaced)));
    fileManager->leaveInsertMode();
}
