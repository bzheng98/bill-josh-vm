#include "insertCommand.h"
#include "insertFootprint.h"
#include "replaceFootprint.h"
#include "vm.h"

void InsertCommand::createInsertFootprint(const Position &start, const Position &end, const Position &cursor) {
    vm->addFootprint(std::unique_ptr<Footprint>(new InsertFootprint(start,end, cursor)));
}

void InsertCommand::createReplaceFootprint(const Position &start, const Position &end, const std::string &replaced) {
    vm->addFootprint(std::unique_ptr<Footprint>(new ReplaceFootprint(start, end, replaced)));
}
