#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <string>
#include <list>
#include <vector>
#include "position.h"

class FileManager {
    const std::string fileName;
    std::list<std::string> lines;
    std::list<std::string>::iterator curLineIter;
    Position cursorPosition;
    int lastCol;
    void insertNewLine();
  public:
    FileManager(const std::string &fileName);
    void setCursorPosition(Position p, bool changeLastCol, bool insertMode = false);
    void setCursorPosition(Position p);
    void moveCursorPosition(int dx, int dy, bool insertMode = false);
    const Position &getCursorPosition() const;
    const std::vector<std::string> getLines(size_t start, size_t n);
    void insertChar(char c);
    void deleteChar();
    void insertText(const std::string &s, const Position &p, int count = 1);
    void deleteText(const Position &start, const Position &end);
    void saveFile();
    void createAndGoToNewLine(bool above);
    void goToEndOfLine(bool insertMode = false);
    void leaveInsertMode();
};
#endif
