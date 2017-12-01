#include "scrollDown.h"
#include "vm.h"

void ScrollDown::update(const CommandInfo &c) {
	if(c.getCommandType() == SCROLLDOWN) {
		vm -> scrollViewsDown();
		fileManager -> setCursorPosition(vm -> getViewCursor());
	}
}
