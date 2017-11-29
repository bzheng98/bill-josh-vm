#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <string>
#include <list>
#include <vector>
#include "position.h"

class FileManager {
    int lastCol;
    const std::string fileName;
    std::list<std::string> lines;
    std::list<std::string>::iterator curLineIter;
    Position cursorPosition;
  public:
    FileManager(const std::string &fileName);
    void setCursorPosition(Position p, bool changeLastCol);
    void setCursorPosition(Position p);
    void moveCursorPosition(int dx, int dy);
    const Position &getCursorPosition() const;
    const std::vector<std::string> getLines(size_t start, size_t n);
    void insertChar(char c);
    void insertText(const std::string &s, const Position &p);
    void deleteText(const Position &start, const Position &end);
    void saveFile();
};
#endif
