#include "fileManager.h"
#include <fstream>
#include <iostream>
#include <algorithm>

FileManager::FileManager(const std::string &fileName): lines{}, curLineIter{}, cursorPosition{0,0} {
    std::ifstream f{fileName};
    std::string s;
    while(getline(f,s)) {
        lines.push_back(s);
    }
    curLineIter = lines.begin();
    //std::cout << "File " << fileName << " opened. " << lines.size() << " lines." << std::endl;
}

void FileManager::setCursorPosition(Position p) {
    int lineDiff = cursorPosition.getLine();
    //if(lines.empty()) {
    //    cursorPosition = Position(0, 0);
    //    return;
    //}
    std::vector<std::string> lines = getLines(0, (this->lines).size());
//    std::cout << "reserved\n";
    p.setLine(std::min((int)lines.size() - 1, p.getLine()));
    p.setLine(std::max(0, p.getLine()));
    if(lines[p.getLine()].empty()) {
        p.setCol(0);
        cursorPosition = p;
        return;
    }
    p.setCol(std::min((int)lines[p.getLine()].size() - 1, p.getCol()));
    p.setCol(std::max(0, p.getCol()));
    cursorPosition = p;

    lineDiff = cursorPosition.getLine() - lineDiff;
    std::advance(curLineIter, lineDiff);
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
    curLineIter->insert(curLineIter->begin()+cursorPosition.getCol(), c);
    cursorPosition.setCol(cursorPosition.getCol()+1);
}

void FileManager::insertText(const std::string &s, const Position &p) {
    throw;
}

void FileManager::deleteText(const Position &start, const Position &end) {
    throw;
}
