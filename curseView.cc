#include "curseView.h"
#include <algorithm>
#include <iostream>
CurseView::CurseView() : topLeft{0, 0} {
    initscr();
    noecho();
    raw();
    keypad(stdscr,TRUE);
}

CurseView::~CurseView() {
    endwin();
}

int CurseView::ceilDiv(int a, int b) {
    return a / b + (a % b != 0 ? 1 : 0);
}

Position CurseView::toScreenPosition(Position p) {
    size_t lines, cols, prevLines = 0;
    getmaxyx(stdscr, lines, cols);
    //partial mode, only displaying 1 line
    if(topLeft.getCol() != 0) {
        int dy = p.getLine() - topLeft.getLine();
        int dx = p.getCol() - topLeft.getCol();
        int dif = dy * cols + dx;
        return Position(p.getLine() + dif / cols, p.getCol() + dif % cols); 
    }
    //1 full line or >= 2 lines
    else {
        size_t topLine = topLeft.getLine();
        for(size_t i = topLine; i < p.getLine(); i++) {
            prevLines += std::max(1, ceilDiv(buffer[i].size(), cols));
        }
        prevLines += p.getCol() / cols;
        return Position(prevLines, p.getCol() % cols);
    }
}
bool CurseView::onScreen(Position p) {
    size_t lines, cols;
    getmaxyx(stdscr, lines, cols);
    Position screenPos = toScreenPosition(p);
    return (screenPos.getLine() >= 0 && screenPos.getLine() < lines) && (screenPos.getCol() >= 0 && screenPos.getCol() <= cols);
}
void CurseView::adjustTopLeft(Position cur) {
    //partial mode, only displaying 1 line
    if(topLeft.getCol() != 0) {
        size_t lines, cols;
        getmaxyx(stdscr, lines, cols);
        //show entire line, if possible
        int totChars = lines * cols;
        if(buffer[topLeft.getLine()].size() <= totChars) {
            topLeft.setCol(0);
        }
        //show part of the line, if the cursor is still on that line
        else if(cur.getLine() == topLeft.getLine()) {
            if(cur.getCol() <= topLeft.getCol()) {
                while(!onScreen(cur) && topLeft.getCol() > 0) {
                    topLeft.setCol(topLeft.getCol() - cols);
                }
            }
            else {
              while(!onScreen(cur) && topLeft.getCol() + 1 < buffer[topLeft.getLine()].size()) {
                    topLeft.setCol(topLeft.getCol() + cols);
              }
            }
            return;
        }
        //cursor out of bounds, must adjust
        if(!onScreen(cur)) {
            if(cur.getLine() <= topLeft.getLine()) {
                while(!onScreen(cur) && topLeft.getLine() > 0) {
                    topLeft.setLine(topLeft.getLine() - 1);
                }
            }
            else {
                while(!onScreen(cur) && topLeft.getLine() + 1  < buffer.size()) {
                    topLeft.setLine(topLeft.getLine() + 1);
                }
            }
        }
    }
}

void CurseView::update(const std::vector<std::string> &buf) {
    Position p(0, 0);
    buffer.clear();
    for(auto s : buf)buffer.push_back(s);
    adjustTopLeft(p);
    //print the buf
    size_t prevX, prevY, lines, cols, idx;
    bool notEnoughLines = false;
    getmaxyx(stdscr, lines, cols);
    getyx(stdscr, prevY, prevX);
    Position cur = topLeft;
    for(size_t i = 0; i < lines - 1; i++) {
        move(i, 0);
        clrtoeol();
    }
    move(prevX, prevY);
    if(topLeft.getCol() != 0) {
        mvaddstr(0, 0, buf[topLeft.getLine()].substr(topLeft.getCol()).c_str());
        return;
    }
    size_t topLine = topLeft.getLine();
    for(idx = topLine; idx < buf.size(); idx++) {
        Position actual = toScreenPosition(cur);
        size_t charsLeft = (lines - 1 - actual.getLine()) * cols;
        if(buf[idx].size() <= charsLeft) {
            mvaddstr(actual.getLine(), 0, buf[idx].c_str());
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
        for(size_t i = actual.getLine(); i < lines - 1; i++) {
            mvaddch(i, 0, pr);
        }
    }
}

bool CurseView::atBottom() {
    
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

void CurseView::updateBottomText(const std::string &s) {
    int lines, cols, prevY, prevX;
    getmaxyx(stdscr, lines, cols);
    getyx(stdscr, prevY, prevX);
    move(lines - 1, 0);
    clrtoeol();
    mvaddstr(lines - 1, 0, s.c_str());
    move(prevY, prevX);
}

//scroll down half
void CurseView::scrollDown(int cnt) {
    int lines, cols;
    getmaxyx(stdscr, lines, cols);
    for(int i = 0; i < (lines - 1) / 2; i++) {
	int sz = buffer[topLeft.getLine()].size();
	if(sz - topLeft.getCol()) {
	    
	}	
    }    
}

//scroll up half
void curseView::scrollUp(int cnt) {
    
}

