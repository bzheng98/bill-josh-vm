#include "fileManager.h"
#include <fstream>
#include <iostream>
#include <algorithm>

FileManager::FileManager(const std::string &fileName): fileName{fileName}, lines{}, curLineIter{}, cursorPosition{0,0}, lastCol{0}, cursor{} {
    cursor.bind(this);
    std::ifstream f{fileName};
    std::string s;
    while(getline(f,s)) {
        lines.push_back(s);
    }
    if (!lines.size())
        lines.push_back("");
    curLineIter = lines.begin();
    //std::cout << "File " << fileName << " opened. " << lines.size() << " lines." << std::endl;
}

void FileManager::setCursorPosition(Position p, bool changeLastCol, bool insertMode) {
    Position oldCursor = cursorPosition;
    int lineDiff = cursorPosition.getLine();
    std::vector<std::string> lines = getLines(0, (this->lines).size());
    p.setLine(std::min((int)lines.size() - 1, p.getLine()));
    p.setLine(std::max(0, p.getLine()));

    lineDiff = p.getLine() - lineDiff;
    std::advance(curLineIter, lineDiff);

    p.setCol(std::min((int)lines[p.getLine()].size() - (insertMode ? 0 : 1), p.getCol()));
	p.setCol(std::max(0, p.getCol()));
    cursorPosition = p;
    
    if(changeLastCol && !(oldCursor.getCol() == cursorPosition.getCol() && oldCursor.getLine() == cursorPosition.getLine())) { 
        lastCol = cursorPosition.getCol();
    }
}

void FileManager::setCursorPosition(Position p) {
    setCursorPosition(p, true);
}

//for basic motion commands, used to save the column to simulate vim
void FileManager::moveCursorPosition(int dx, int dy, bool insertMode) {
   Position p = cursorPosition;
   p.setLine(p.getLine() + dy);
   p.setCol(p.getCol() + dx); 
   if(dx == 0) {
       p.setCol(lastCol);
       setCursorPosition(p, false, insertMode);
   }
   else {
       setCursorPosition(p, true, insertMode);
   }
}

const Position &FileManager::getCursorPosition() const {
    return cursorPosition;
}

const std::vector<std::string> FileManager::getLines(size_t start, size_t n) {
    std::vector<std::string> ret;
    ret.reserve(n);
    auto it = lines.begin();
    while(start-- && it != lines.end()) ++it;
    while(n-- && it != lines.end()) {
        ret.push_back(*it);
        ++it;
    }
    //std::cout << "updating view with: " << ret.size() << " lines." << std::endl;
    return ret;
}

void FileManager::insertChar(char c) {
    if (c == '\n') {
        insertNewLine();
        return;
    }
    curLineIter->insert(curLineIter->begin()+cursorPosition.getCol(), c);
    moveCursorPosition(1,0,true);
}

int FileManager::deleteChar() {
    int c = cursorPosition.getCol();
    if (!c) {
        int r = cursorPosition.getLine();
        if (r) {
            auto it = std::prev(curLineIter);
            cursorPosition.setLine(r-1);
            cursorPosition.setCol(it->size());
            it->append(*curLineIter);
            lines.erase(curLineIter);
            curLineIter = it;
            return '\n';
        }
        return -1;
    }
    char ret = (*curLineIter)[c-1];
    curLineIter->erase(c-1,1);
    cursorPosition.setCol(c-1);
    return ret;
}

void FileManager::insertNewLine() {
    auto it = curLineIter;
    ++curLineIter;
    curLineIter = lines.insert(curLineIter, it->substr(cursorPosition.getCol()));
    *it = it->substr(0,cursorPosition.getCol());
    cursorPosition.setLine(cursorPosition.getLine()+1);
    cursorPosition.setCol(0);
}

void FileManager::insertText(const std::string &s, const Position &p, int count) {
    if (!count) return;
    setCursorPosition(p, true, true);
    size_t newLine = 0;
    size_t prev = 0;
    while((newLine = s.find('\n', prev)) != std::string::npos) {
        curLineIter->insert(cursorPosition.getCol(), s.substr(prev, newLine-prev));
        cursorPosition.setCol(cursorPosition.getCol()+newLine-prev);
        insertNewLine();
        prev = newLine+1;
    }
    curLineIter->insert(cursorPosition.getCol(), s.substr(prev));
    cursorPosition.setCol(cursorPosition.getCol()+s.length()-prev);
    insertText(s, cursorPosition, count-1);
}

std::string FileManager::replaceText(const std::string &s, const Position &p, int count) {
    if (!count) return "";
    setCursorPosition(p, true, true);
    std::string replaced;
    for (size_t i = 0; i < s.length(); ++i) {
        int k = replaceChar(s[i]);
        if (k != -1) replaced.push_back((char)k);
    }
    return replaced + replaceText(s, p, count-1);;
}

#include <iostream>
std::string FileManager::deleteText(const Range &range) {
    const Position &begin = range.getStart();
    const Position &end = range.getEnd();
    int l = begin.getLine();
    auto firstRowIter = lines.begin();
    std::advance(firstRowIter, l);
    auto lastRowIter = firstRowIter;
    if (end.getLine() >= lines.size())
        lastRowIter = lines.end();
    else
        std::advance(lastRowIter, end.getLine()-l);
    std::string lastRowRemaining = (lastRowIter == lines.end())? "": lastRowIter->substr(end.getCol());
    std::string deleted = firstRowIter->substr(begin.getCol());
    firstRowIter->erase(begin.getCol());
    firstRowIter->append(lastRowRemaining);
    if (begin.getLine() < end.getLine()) {
        firstRowIter = std::next(firstRowIter);
        for (auto it = firstRowIter; it != lastRowIter; ++it) {
            deleted += '\n';
            deleted += *it;
        }
        deleted += '\n';
        deleted += (lastRowIter == lines.end())? "": lastRowIter->substr(0, end.getCol());
        lines.erase(firstRowIter, (lastRowIter == lines.end())? lastRowIter: std::next(lastRowIter));
        if (lastRowIter == lines.end() && lines.size() > 1) lines.pop_back();
    }
    else {
        deleted = deleted.substr(0, end.getCol()-begin.getCol());
    }
    return deleted;
}

void FileManager::saveFile(std::string fileName) {
    if (!fileName.length()) fileName = this->fileName;
    std::ofstream f{fileName};
    for (const auto &line: lines) {
        f << line << std::endl;
    }
}

void FileManager::createAndGoToNewLine(bool above) {
    if (!above) {
        ++curLineIter;
        cursorPosition.setLine(cursorPosition.getLine()+1);
    }
    curLineIter = lines.insert(curLineIter, "");
    cursorPosition.setCol(0);
}

void FileManager::goToEndOfLine(bool insertMode) {
    cursorPosition.setCol(curLineIter->size() - (insertMode? 0:1));
}

void FileManager::leaveInsertMode() {
    moveCursorPosition(-1,0,true);
}

void FileManager::moveCursorBack() {
    if (cursorPosition.getCol())
        moveCursorPosition(-1,0);
    else if (cursorPosition.getLine()) {
        --curLineIter;
        cursorPosition.setLine(cursorPosition.getLine()-1);
        cursorPosition.setCol(curLineIter->size()-1);
    }
}

int FileManager::replaceChar(char c) {
    int col = cursorPosition.getCol();
    int k = -1;
    if (c != '\n' && col < curLineIter->size()) {
        k = (*curLineIter)[col];
        curLineIter->erase(col, 1);
    }
    insertChar(c);
    return k;
}

std::string FileManager::getText(const Range &range) {
    const Position &start = range.getStart();
    const Position &end = range.getEnd();
    auto it = lines.begin();
    std::advance(it, start.getLine());
    if (start.getLine() == end.getLine()) {
        return it->substr(start.getCol(), end.getCol()-start.getCol());
    }
    std::string s = it->substr(start.getCol());
    for (int i = 1; i < end.getLine()-start.getLine(); ++i) {
        ++it;
        s += *it;
    }
    ++it;
    s += it->substr(0, end.getCol());
    return s;
}

char FileManager::getCharAtCursor() {
    if (cursorPosition.getCol() == curLineIter->length()) return '\n';
    return (*curLineIter)[cursorPosition.getCol()];
}

int FileManager::getCurrentLineLength() {
    return curLineIter->length();
}
