#include "scrollForward.h"
#include "vm.h"
void ScrollForward::update(const CommandInfo &c) {
	if(c.getCommandType() == SCROLLFORWARD) {
		for(int i = 0; i < c.getCount(); i++) {
			vm->scrollViewsForward();	
		}
		fileManager -> setCursorPosition(vm -> getViewCursor());
	}
}
