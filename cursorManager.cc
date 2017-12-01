#include "cursorManager.h"
#include "fileManager.h"

Position CursorManager::getNext(bool countNewline) {
    int curlen = fm->curLineIter->length();
    if (countNewline) ++curlen;
    Position ret = fm->cursorPosition;
    if (ret.getCol() < curlen - 1) {
        ret.setCol(ret.getCol()+1);
    }
    else if (std::next(fm->curLineIter) != fm->lines.end()) {
        ret.setLine(ret.getLine()+1);
        ret.setCol(0);
    }
    return ret;
}

Position CursorManager::getPrev(bool countNewline) {
    Position ret = fm->cursorPosition;
    if (ret.getCol())
        ret.setCol(ret.getCol()-1);
    else if (ret.getLine()) {
        auto prevLineIter = std::prev(fm->curLineIter);
        ret.setLine(ret.getLine()+1);
        int len = prevLineIter->length();
        if (countNewline) ++len;
        ret.setCol(len-1);
    }
    return ret;
}

Position CursorManager::getForwardWord() {
    Position original = fm->cursorPosition;
    Position prevPos{-1,-1};
    while (fm->cursorPosition != prevPos) {
        prevPos = fm->cursorPosition;
        char c = fm->getCharAtCursor();
        bool num = c >= '0' && c <= '9';
        bool alpha = c >= 'a' && c <= 'z';
        bool ALPHA = c >= 'A' && c <= 'Z';
        if (!num && !alpha && !ALPHA) break;
        fm->setCursorPosition(getNext(true), false, true);
    }
    if (fm->cursorPosition == prevPos) {
        fm->setCursorPosition(original, false, true);
        return prevPos;
    }
    fm->setCursorPosition(getNext(true), false, true);
    while (fm->cursorPosition != prevPos) {
        prevPos = fm->cursorPosition;
        char c = fm->getCharAtCursor();
        if (c == ' ' || c == '\n') break;
        fm->setCursorPosition(getNext(true), false, true);
    }
    prevPos = fm->cursorPosition;
    fm->setCursorPosition(original, false, true);
    return prevPos;
}

Position CursorManager::getBackWord() {
    throw;
}

Position CursorManager::getLeft() {
    throw;
}

Position CursorManager::getRight() {
    throw;
}

Position CursorManager::getUp() {
    throw;
}

Position CursorManager::getDown() {
    throw;
}
