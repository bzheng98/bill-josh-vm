#include "curseView.h"

CurseView::CurseView() {
    initscr();
    noecho();
    raw();
}

CurseView::~CurseView() {
    endwin();
}

void CurseView::update(const std::vector<std::string> buf&) {
    //copy the buf over?
}

void CurseView::updateView() {
    //display the view
}
