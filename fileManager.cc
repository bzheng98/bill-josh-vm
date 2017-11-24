#include "fileManager.h"

FileManager::FileManager(const std::string &fileName): cursorPosition{0,0} {
}

const Position &FileManager::getCursorPosition() const {
}

void FileManager::insertText(const std::string &s, const Position &p) {
}

void FileManager::deleteText(const Position &start, const Position &end) {
}
