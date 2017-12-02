#include "scrollForward.h"
#include "vm.h"
void ScrollForward::update(const CommandInfo &c) {
	if(c.getCommandType() == SCROLLFORWARD) {
		vm->scrollViewsForward();	
		fileManager -> setCursorPosition(vm -> getViewCursor());
	}
}
