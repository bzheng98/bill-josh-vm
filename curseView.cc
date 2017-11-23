#include "curseView.h"

CurseView::CurseView() {
    initscr();
    noecho();
    raw();
}

CurseView::~CurseView() {
    endwin();
}

int CurseView::ceilDiv(int a, int b) {
    return a / b + (a % b != 0 ? 1 : 0);
}

Position CurseView::toScreenPosition(Position p) {
    int lines, cols, prevLines = 0;
    getmaxyx(stdscr, lines, cols);
    for(int i = topLine; i < p.getLine; i++) {
        prevLines += ceilDiv(buffer[i].size(), cols);
    }
    prevLines += p.getCol() / cols;
    return Position(prevLines, p.getCol() % cols);
}

void CurseView::update(const std::vector<std::string> buf&) {
    //print the buf
    int prevX, prevY, lines, cols, idx;
    bool notEnoughLines = false;
    getmaxyx(stdscr, lines, cols);
    getyx(stdscr, prevY, prevX);
    Position cur = Position(topLine, 0);
    for(int i = 0; i < lines - 1; i++) {
        move(i, 0);
        clrtoeol();
    }
    move(prevX, prevY);
    for(idx = topLine; idx < buf.size(); idx++) {
        Position actual = toScreenPosition(cur);
        int charsLeft = (lines - 1 - actual.getLine()) * cols;
        if(buf[idx].size() <= charsLeft) {
            mvaddstr(actual.getLine(), 0, buf[idx]);
            cur.setLine(cur.getLine() + 1);
        }
        else {
            notEnoughLines = true;
            break;
        }
    }
    Position actual = toScreenPosition(cur);
    if(actual.getLine() < lines - 1) {
        char pr = notEnoughLines ? '@' : '~';
        for(int i = actual.getLine(); i < lines - 1; i++) {
            mvaddch(i, 0, pr);
        }
    }
}

void CurseView::updateCursor(Position p) {
    //update the cursor
    Position newPos = toScreenPosition(p);
    move(newPos.getLine(), newPos.getCol());
}

void CurseView::updateView() {
    //display the view
    refresh();
}
