#include "curseView.h"
#include <algorithm>
#include <iostream>
#include <fstream>
CurseView::CurseView() : topLeft{0, 0}, curCursor{0, 0} {
    initscr();
    noecho();
    raw();
    start_color();
    keypad(stdscr,TRUE);
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
    //partial mode, only displaying 1 line
    if(inPartialMode() && false) {
        int dy = p.getLine() - topLeft.getLine();
        int dx = p.getCol() - topLeft.getCol();
        int dif = dy * cols + dx;
        return Position(dif / cols, dif % cols); 
    }
    //1 full line or >= 2 lines
    else {
        int topLine = topLeft.getLine(), actualTopLine = 0;
        for(int i = 0; i < std::max(p.getLine(), topLeft.getLine()); i++) {
            int tot = std::max(1, ceilDiv(buffer[i].size(), cols));
            if(i < p.getLine()) {
                prevLines += tot; 
            }
            if(i < topLeft.getLine()) {
                actualTopLine += tot;
            }
        }
        prevLines += p.getCol() / cols;
        return Position(prevLines - actualTopLine, p.getCol() % cols);
    }
}

bool CurseView::onScreen(Position p) {
    if(inPartialMode() && p.getLine() != topLeft.getLine())return false;
    int lines, cols;
    getmaxyx(stdscr, lines, cols);
    Position screenPos = toScreenPosition(p);
    return (screenPos.getLine() >= 0 && screenPos.getLine() <= lines - 2) && (screenPos.getCol() >= 0 && screenPos.getCol() <= cols - 1);
}

bool CurseView::inPartialMode() {
    if(topLeft.getCol() != 0) {
        return true;
    }
    int lines, cols;
    getmaxyx(stdscr, lines, cols);
    return buffer[topLeft.getLine()].size() > (lines - 1) * cols;
}


void CurseView::adjustTopLeft(Position cur) {
    //partial mode, only displaying 1 line
    if(inPartialMode()) {
        int lines, cols;
        getmaxyx(stdscr, lines, cols);
        //show entire line, if possible
        int totChars = (lines - 1) * cols;
        if(buffer[topLeft.getLine()].size() <= totChars || cur.getLine() != topLeft.getLine()) {
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
    }
    //cursor out of bounds, must adjust
    if(!onScreen(cur)) {
        if(cur.getLine() < topLeft.getLine()) {
			while(!onScreen(cur) && topLeft.getLine() > 0) {
                topLeft.setLine(topLeft.getLine() - 1);
            }
        }
        else {
            while(!onScreen(cur) && topLeft.getLine() + 1 < buffer.size()) {
                topLeft.setLine(topLeft.getLine() + 1);
            }
        }
    }
}

void CurseView::update(const std::vector<std::string> &buf, Position p) {
    std::ofstream f;
    f.open("out.txt");
    buffer.clear();
    for(auto s : buf)buffer.push_back(s);
    ColoredBuffer colorBuf (buf); 
    f << "adjusted\n";
    //print the buf
    size_t prevX, prevY, lines, cols, idx;
    bool notEnoughLines = false;
    getmaxyx(stdscr, lines, cols);
    getyx(stdscr, prevY, prevX);
    for(size_t i = 0; i < lines - 1; i++) {
        move(i, 0);
        clrtoeol();
    }
    move(prevX, prevY); 
    if(buf.empty())return;
	adjustTopLeft(p);	
    f << topLeft.getLine() << " " << topLeft.getCol() << "\n";
	if(inPartialMode()) {
        mvaddstr(0, 0, buf[topLeft.getLine()].substr(topLeft.getCol(), (lines - 1) * cols).c_str());
        return;
    }
	Position cur = topLeft;
    size_t topLine = topLeft.getLine();
    for(idx = topLine; idx < buf.size(); idx++) {
        //f << "cur: " << cur.getLine() << " " << cur.getCol() << "\n";
        Position actual = toScreenPosition(cur);
        //f << "actual: " << actual.getLine() << " " << actual.getCol() << "\n";
        size_t charsLeft = (lines - 1 - actual.getLine()) * cols;
        if(buf[idx].size() <= charsLeft) {
            move(actual.getLine(), 0);
            colorPrint(buf[idx].c_str(), colorBuf.getColor(idx)); 
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
        init_pair(13, COLOR_BLUE, COLOR_BLACK);
        for(size_t i = actual.getLine(); i < lines - 1; i++) {
            mvaddch(i, 0, pr | COLOR_PAIR(13));
        }
    }
}

void CurseView::colorPrint(const std::string &s, const std::vector<int> &color) {
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    for(int i = 0; i < color.size(); i++) {
        addch(s[i] | COLOR_PAIR(color[i]));
    }
}

void CurseView::updateCursor(Position p) {
    std::ofstream f;
    f.open("cursor.txt");
	//update the cursor
	curCursor = p;
	f << p.getLine() << " " << p.getCol() << "\n";
    Position newPos = toScreenPosition(p);
	f << newPos.getLine() << " " << newPos.getCol() << "\n";
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

bool CurseView::atBottom() {
	int lines, cols;
	getmaxyx(stdscr, lines, cols);
	int linesLeft = lines - 1;
	for(int i = topLeft.getLine(); i < buffer.size(); i++) {
		linesLeft -= std::max(1, ceilDiv(buffer[i].size(), cols));
	}
	return linesLeft >= 0;
}

bool CurseView::atTop() {
	return topLeft.getLine() == 0 && topLeft.getCol() == 0;
}

void CurseView::scrollEnd() {
	if(topLeft.getCol() != 0) {
		int sz = buffer[topLeft.getLine()].size();
		if(topLeft.getCol() < sz / 2) {
			topLeft.setCol(0);		
		}
		else {
			topLeft.setCol(0);
			topLeft.setLine(topLeft.getLine() + 1);
		}
	}
}

//half a page
void CurseView::scrollDown() {
	if(buffer.empty())return;
	int lines, cols;
	getmaxyx(stdscr, lines, cols);
	int cnt = (lines - 1) / 2;
	for(int i = 0; i < cnt; i++) {
		if(atBottom())break;
		int sz = buffer[topLeft.getLine()].size();
		topLeft.setCol(topLeft.getCol() + cols);
		if(topLeft.getCol() >= sz) {
			topLeft.setLine(topLeft.getLine() + 1);
			topLeft.setCol(0);
		}
	}
	scrollEnd();
	updateCursor(topLeft);
}

//half a page
void CurseView::scrollUp() {
	if(buffer.empty())return;
	int lines, cols;
	getmaxyx(stdscr, lines, cols);
	int cnt = (lines - 1) / 2;
	for(int i = 0; i < cnt; i++) {
		if(atTop())break;
		int sz = buffer[topLeft.getLine()].size();
		if(topLeft.getCol() == 0) {
			topLeft.setLine(topLeft.getLine() - 1);
			topLeft.setCol(((sz - 1) / cols) * cols);
		}
		else {
			topLeft.setCol(topLeft.getCol() - cols);
		}
	}
	scrollEnd();
	updateCursor(topLeft);
}

//a full page (down)
void CurseView::scrollForward() {
	if(buffer.empty())return;
	int lines, cols;
	getmaxyx(stdscr, lines, cols);
	int cnt = lines - 1;
	for(int i = 0; i < cnt; i++) {
		if(topLeft.getLine() == buffer.size() - 1)break;
		int sz = buffer[topLeft.getLine()].size();
		topLeft.setCol(topLeft.getCol() + cols);
		if(topLeft.getCol() >= sz) {
			topLeft.setLine(topLeft.getLine() + 1);
			topLeft.setCol(0);
		}
	}
	scrollEnd();
	updateCursor(topLeft);
}

//a full page (up)
void CurseView::scrollBackward() {
	if(buffer.empty())return;
	int lines, cols;	
	getmaxyx(stdscr, lines, cols);
	int cnt = lines - 1;
	for (int i = 0; i < cnt; i++) {
		if(atTop())break;
		int sz = buffer[topLeft.getLine()].size();
		if(topLeft.getCol() == 0) {
			topLeft.setLine(topLeft.getLine() - 1);
			topLeft.setCol(((sz - 1) / cols) * cols);
		}
		else {
			topLeft.setCol(topLeft.getCol() - cols);
		}
	}
	scrollEnd();
	//make the cursor point to bottom of screen
	updateCursor(getBottom());
}

Position CurseView::getBottom() {
	Position ret = topLeft;
	int lines, cols;
	getmaxyx(stdscr, lines, cols);
	for(int i = 0; i < lines - 2; i++) {
		if(ret.getLine() == buffer.size() - 1)break;
		int sz = buffer[topLeft.getLine()].size();
		ret.setCol(ret.getCol() + cols);
		if(ret.getCol() >= sz) {
			ret.setLine(ret.getLine() + 1);
			ret.setCol(0);
		} 
	}
	if(ret.getCol() != 0) {
		ret.setLine(ret.getLine() - 1);
		ret.setCol(0);
	}
	return ret;
}

Position CurseView::getCursor() {
	return curCursor;
}
