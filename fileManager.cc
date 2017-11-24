#include "fileManager.h"
#include <fstream>
#include <iostream>

FileManager::FileManager(const std::string &fileName): lines{}, curLineIter{lines.begin()}, cursorPosition{0,0} {
    std::ifstream f{fileName};
    std::string s;
    while(getline(f,s)) {
        lines.push_back(s);
    }
    std::cout << "File " << fileName << " opened. " << lines.size() << " lines." << std::endl;
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
    std::cout << "getLines success" << std::endl;
    return ret;
}

void FileManager::insertChar(char c) {
    curLineIter->insert(curLineIter->begin()+cursorPosition.getCol(), c);
}

void FileManager::insertText(const std::string &s, const Position &p) {
    throw;
}

void FileManager::deleteText(const Position &start, const Position &end) {
    throw;
}
