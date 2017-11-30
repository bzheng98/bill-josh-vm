#include "fileManager.h"
#include <fstream>
#include <iostream>
#include <algorithm>

FileManager::FileManager(const std::string &fileName): fileName{fileName}, lines{}, curLineIter{}, cursorPosition{0,0}, lastCol{0} {
    std::ifstream f{fileName};
    std::string s;
    while(getline(f,s)) {
        lines.push_back(s);
    }
    curLineIter = lines.begin();
    //std::cout << "File " << fileName << " opened. " << lines.size() << " lines." << std::endl;
}

void FileManager::setCursorPosition(Position p, bool changeLastCol, bool insertMode) {
    Position oldCursor = cursorPosition;
    int lineDiff = cursorPosition.getLine();
    std::vector<std::string> lines = getLines(0, (this->lines).size());
    p.setLine(std::min((int)lines.size() - 1, p.getLine()));
    p.setLine(std::max(0, p.getLine()));

    lineDiff = cursorPosition.getLine() - lineDiff;
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
    cursorPosition.setCol(cursorPosition.getCol()+1);
}

void FileManager::deleteChar() {
    int c = cursorPosition.getCol();
    if (!c) return;
    curLineIter->erase(c-1,1);
    cursorPosition.setCol(c-1);
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

void FileManager::deleteText(const Position &start, const Position &end) {
    throw;
}

void FileManager::saveFile() {
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
    cursorPosition.setCol(std::min(cursorPosition.getCol(), std::max(0,(int)curLineIter->size()-1)));
}
