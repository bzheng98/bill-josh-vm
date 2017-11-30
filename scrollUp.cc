#include "scrollUp.h"
void ScrollUp::update(const CommandInfo &c) {
	if(c.getCommandType() == SCROLLUP) {
		vm -> scrollViewsUp();
	}
}
