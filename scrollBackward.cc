#include "scrollBackward.h"
#include "vm.h"
void ScrollBackward::update(const CommandInfo &c) {
	if(c.getCommandType() == SCROLLBACKWARD) {
		for(int i = 0; i < c.getCount(); i++) {
			vm->scrollViewsBackward();	
		}
		fileManager -> setCursorPosition(vm -> getViewCursor());
	}
}
