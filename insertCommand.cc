#include "insertCommand.h"
#include "insertFootprint.h"
#include "vm.h"

void InsertCommand::createInsertFootprint(const Position &start, const Position &end, const Position &cursor) {
    vm->addFootprint(std::unique_ptr<Footprint>(new InsertFootprint(start,end, cursor)));
}
