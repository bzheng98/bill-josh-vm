#ifndef CURSE_VIEW_H
#define CURSE_VIEW_H

#include "view.h"
#include "coloredBuffer.h"
#include <ncurses.h>

class CurseView: public View {
    Position topLeft, curCursor;
    std::vector<std::string> buffer;
    int ceilDiv(int a, int b);
    Position toScreenPosition(Position p);
    bool onScreen(Position p);
    void adjustTopLeft(Position p);
	void scrollEnd();
    void colorPrint(const std::string &s, const std::vector<int> &color);
	bool atBottom();
	bool atTop();	
	bool inPartialMode();
    Position getBottom();
	public:
        CurseView();
        ~CurseView() override;
		void update(const std::vector<std::string> &buf, Position p) override;
        void updateCursor(Position p) override;
        void updateView() override;
        void updateBottomText(const std::string &s) override;
		void scrollDown() override;
		void scrollUp() override;
		void scrollForward() override;
		void scrollBackward() override;
		Position getCursor() override;
};
#endif
