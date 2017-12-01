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
    Position getForwardWord();
    Position getBackWord();
    Position getLeft();
    Position getRight();
    Position getUp();
    Position getDown();
    Position findForward(char c);
    Position findBackward(char c);
    Position getLine(int line);
    Position getLastLine();
    Position getFirstLine();
};
#endif
