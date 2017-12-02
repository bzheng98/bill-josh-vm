#include "scrollBackward.h"
#include "vm.h"
void ScrollBackward::update(const CommandInfo &c) {
	if(c.getCommandType() == SCROLLBACKWARD) {
		vm->scrollViewsBackward();	
		fileManager -> setCursorPosition(vm -> getViewCursor());
	}
}
