#include "insertCommand.h"
#include "insertFootprint.h"
#include "vm.h"

void InsertCommand::createInsertFootprint(const Position &start, const Position &end) {
    vm->addFootprint(std::unique_ptr<Footprint>(new InsertFootprint(start,end)));
}
