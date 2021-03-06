#ifndef VIEW_H
#define VIEW_H

#include <string>
#include <vector>
#include "position.h"

class View{
public:
    virtual ~View() = default;
    virtual void update(const std::vector<std::string> &buf, Position p) = 0;
    virtual void updateCursor(Position p) = 0;
    virtual void updateView() = 0;
    virtual void updateBottomText(const std::string &s) = 0;
    virtual void scrollDown() = 0;
    virtual void scrollUp() = 0;
	virtual void scrollForward() = 0;
	virtual void scrollBackward() = 0;
	virtual Position getCursor() = 0;
};
#endif
