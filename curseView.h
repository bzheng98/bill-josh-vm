#ifndef CURSE_VIEW_H
#define CURSE_VIEW_H

#include "view.h"
#include <ncurses.h>

class CurseView: public View {
    int topLine = 0;
    std::vector<std::string> buffer;
    int ceilDiv(int a, int b);
    Position toScreenPosition(Position p);
    public:
        CurseView();
        ~CurseView() override;
        void update(const std::vector<std::string> &buf) override;
        void updateCursor(Position p) override;
        void updateView() override;
};
#endif
