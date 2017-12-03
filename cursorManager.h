#ifndef CURSORMANAGER_H
#define CURSORMANAGER_H
#include "position.h"

class FileManager;

class CursorManager {
    FileManager *fm;
  public:
    CursorManager(): fm{nullptr} {}
    void bind(FileManager *fm) { this->fm = fm; }
    Position getNext(bool countNewline);
    Position getPrev(bool countNewline);
    Position getForwardWord(int count);
    Position getBackWord(int count);
    Position getLeft(int count);
    Position getRight(int count);
    Position getUp(int count);
    Position getDown(int count);
    Position findForward(char c, int count);
    Position findBack(char c, int count);
    Position getLineBegin();
    Position getLineEnd(int count);
    Position getLine(int line);
    Position getMatch();
};
#endif
