#include "deleteCommand.h"
#include <string>
#include <memory>
#include "deleteFootprint.h"

void DeleteCommand::deleteRange(const Range &range) {
    std::string deleted = fileManager->deleteText(range, true);
    fileManager->setCursorPosition(range.getStart());
    vm->addFootprint(std::unique_ptr<Footprint>(new DeleteFootprint(range.getStart(), deleted)));
    writeToRegister(deleted);
}
