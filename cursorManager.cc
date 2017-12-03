#include "cursorManager.h"
#include "fileManager.h"
#include <algorithm>

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
        ret.setLine(ret.getLine()-1);
        int len = prevLineIter->length();
        if (countNewline) ++len;
        ret.setCol(len-1);
    }
    return ret;
}

bool is_alphanumeric(char c) {
    bool num = c >= '0' && c <= '9';
    bool alpha = c >= 'a' && c <= 'z';
    bool ALPHA = c >= 'A' && c <= 'Z';
    return num || alpha || ALPHA;
}
bool is_whitespace(char c) {
    return c == ' ';
}
bool is_newline(char c) {
    return c == '\n';
}

Position CursorManager::getForwardWord(int count) {
    if (!count) return fm->cursorPosition;
    Position original = fm->cursorPosition;
    bool alphaNum = is_alphanumeric(fm->getCharAtCursor());
    Position prevPos{-1,-1};
    char c;
    while (fm->cursorPosition != prevPos) {
        c = fm->getCharAtCursor();
        if (alphaNum) {
            if (!is_alphanumeric(c))
                break;
        }
        else {
            if (is_whitespace(c) || is_alphanumeric(c)) break;
        }
        prevPos = fm->cursorPosition;
        fm->setCursorPosition(getNext(true), false, true);
    }
    int newlineCount = 0;
    while (fm->cursorPosition != prevPos) {
        c = fm->getCharAtCursor();
        if (is_newline(c)) {
            ++newlineCount;
            if (newlineCount >= 2) break;
        }
        else if (!is_whitespace(c)) break;
        prevPos = fm->cursorPosition;
        fm->setCursorPosition(getNext(true), false, true);
    }
    prevPos = getForwardWord(count-1);
    fm->setCursorPosition(original, false, true);
    return prevPos;
}

Position CursorManager::getBackWord(int count) {
    if (!count) return fm->cursorPosition;
    Position original = fm->cursorPosition;
    Position prevPos = original;
    fm->setCursorPosition(getPrev(true), false, true);
    if (fm->cursorPosition == original) return original;
    int newlineCount = 0;
    char c;
    while (fm->cursorPosition != prevPos) {
        c = fm->getCharAtCursor();
        if (is_newline(c)) {
            ++newlineCount;
            if (newlineCount >= 2) break;
        }
        else if (!is_whitespace(c)) break; 
        prevPos = fm->cursorPosition;
        fm->setCursorPosition(getPrev(true), false, true);
    }
    if (is_newline(c)) {
        fm->setCursorPosition(prevPos, false, true);
        prevPos = getBackWord(count-1);
        fm->setCursorPosition(original, false, true);
        return prevPos;
    }
    bool alphanum = is_alphanumeric(c);
    while (fm->cursorPosition != prevPos) {
        c = fm->getCharAtCursor();
        if (alphanum) {
            if (!is_alphanumeric(c)) break;
        }
        else {
            if (is_whitespace(c) || is_alphanumeric(c)) break;
        }
        prevPos = fm->cursorPosition;
        fm->setCursorPosition(getPrev(true), false, true);
    }
    fm->setCursorPosition(prevPos, false, true);
    prevPos = getBackWord(count-1);
    fm->setCursorPosition(original, false, true);
    return prevPos;
}

Position CursorManager::getLeft(int count) {
    if (!count) return fm->cursorPosition;
    Position original = fm->cursorPosition;
    fm->moveCursorPosition(-1,0);
    Position newPos = getLeft(count-1);
    fm->setCursorPosition(original, false, true);
    return newPos;
}

Position CursorManager::getRight(int count) {
    if (!count) return fm->cursorPosition;
    Position original = fm->cursorPosition;
    fm->moveCursorPosition(1,0);
    Position newPos = getRight(count-1);
    fm->setCursorPosition(original, false, true);
    return newPos;
}

Position CursorManager::getUp(int count) {
    if (!count) return fm->cursorPosition;
    Position original = fm->cursorPosition;
    fm->moveCursorPosition(0,-1);
    Position newPos = getUp(count-1);
    fm->setCursorPosition(original, false, true);
    return newPos;
}

Position CursorManager::getDown(int count) {
    if (!count) return fm->cursorPosition;
    Position original = fm->cursorPosition;
    fm->moveCursorPosition(0,1);
    Position newPos = getDown(count-1);;
    fm->setCursorPosition(original, false, true);
    return newPos;
}

Position CursorManager::findForward(char c, int count) {
    if (!count) return fm->cursorPosition;
    int found = 0;
    for (int i = fm->cursorPosition.getCol()+1; i < fm->curLineIter->length(); ++i) {
        if ((*fm->curLineIter)[i] == c) {
            ++found;
            if (found == count) {
                return Position{fm->cursorPosition.getLine(), i};
            }
        }
    }
    return fm->cursorPosition;
}

Position CursorManager::findBack(char c, int count) {
    if (!count) return fm->cursorPosition;
    int found = 0;
    for (int i = fm->cursorPosition.getCol()-1; i >= 0; --i) {
        if ((*fm->curLineIter)[i] == c) {
            ++found;
            if (found == count) {
                return Position{fm->cursorPosition.getLine(), i};
            }
        }
    }
    return fm->cursorPosition;
}

Position CursorManager::getLineBegin() {
    Position p = fm->cursorPosition;
    p.setCol(0);
    return p;
}

Position CursorManager::getLineEnd(int count) {
    Position original = fm->cursorPosition;
    Position p = fm->cursorPosition;
    p.setLine(std::min((int)fm->lines.size()-1, p.getLine()+count-1));
    fm->setCursorPosition(p, false, true);
    p.setCol(fm->curLineIter->length());
    fm->setCursorPosition(original, false, true);
    return p;
}

Position CursorManager::getLine(int line) {
    Position original = fm->cursorPosition;
    line = std::max(line, 1);
    fm->setCursorPosition(Position{line-1,0}, false, true);
    Position p = fm->cursorPosition;
    fm->setCursorPosition(original, false, true);
    return p;
}

bool is_open_bracket(char c) {
    return c == '(' || c == '{' || c == '[';
}
bool is_close_bracket(char c) {
    return c == ')' || c == '}' || c == ']';
}
char get_match(char c) {
    if (c == '(') return ')';
    if (c == '{') return '}';
    if (c == '[') return ']';
    if (c == ')') return '(';
    if (c == '}') return '{';
    if (c == ']') return ']';
}

Position CursorManager::getMatch() {
    Position original = fm->cursorPosition;
    Position prev = original;
    if (prev.getCol() == 0) {
        std::string s = fm->curLineIter->substr(0,6);
        if (s.find("#if") == 0
            || s.find("#elif") == 0
            || s.find("#else") == 0) {
            int count = 1;
            fm->moveCursorPosition(0,1,true);
            while (fm->cursorPosition != prev) {
                prev = fm->cursorPosition;
                s = fm->curLineIter->substr(0,6);
                if (count == 1 &&
                    (s.find("#elif") == 0
                    || s.find("#else") == 0
                    || s.find("#endif") == 0)) {
                    fm->setCursorPosition(original, false, true);
                    return prev;
                }
                if (s.find("#if") == 0) ++count;
                else if (s.find("#endif") == 0) --count;
                fm->moveCursorPosition(0,1,true);
            }
            fm->setCursorPosition(original, false, true);
            return original;
        }
        else if (fm->curLineIter->find("#endif") == 0) {
            int count = 1;
            fm->moveCursorPosition(0,-1,true);
            while (fm->cursorPosition != prev) {
                prev = fm->cursorPosition;
                s = fm->curLineIter->substr(0,6);
                if (count == 1 && s.find("#if") == 0) {
                    fm->setCursorPosition(original, false, true);
                    return prev;
                }
                if (s.find("#if") == 0) --count;
                else if (s.find("#endif") == 0) ++count;
                fm->moveCursorPosition(0,-1,true);
            }
            fm->setCursorPosition(original, false, true);
            return original;
        }
    }
    for (int i = fm->cursorPosition.getCol(); i < fm->curLineIter->length(); ++i) {
        if (is_open_bracket((*fm->curLineIter)[i])) {
            char open = (*fm->curLineIter)[i];
            char close = get_match(open);
            int count = 1;
            prev.setCol(i);
            fm->setCursorPosition(prev, false, true);
            fm->setCursorPosition(getNext(false), false, true);
            while(fm->cursorPosition != prev) {
                prev = fm->cursorPosition;
                char c = fm->getCharAtCursor();
                if (c == open) ++count;
                else if (c == close) --count;
                if (!count) {
                    fm->setCursorPosition(original, false, true);
                    return prev;
                }
                fm->setCursorPosition(getNext(false), false, true);
            }
            fm->setCursorPosition(original, false, true);
            return original;
        }
        else if (is_close_bracket((*fm->curLineIter)[i])) {
            char close = (*fm->curLineIter)[i];
            char open = get_match(close);
            int count = 1;
            prev.setCol(i);
            fm->setCursorPosition(prev, false, true);
            fm->setCursorPosition(getPrev(false), false, true);
            while(fm->cursorPosition != prev) {
                prev = fm->cursorPosition;
                char c = fm->getCharAtCursor();
                if (c == close) ++count;
                else if (c == open) --count;
                if (!count) {
                    fm->setCursorPosition(original, false, true);
                    return prev;
                }
                fm->setCursorPosition(getPrev(false), false, true);
            }
            fm->setCursorPosition(original, false, true);
            return original;
        }
        else if (fm->curLineIter->substr(i,2) == "/*") {
            prev.setCol(i);
            fm->setCursorPosition(prev, false, true);
            fm->setCursorPosition(getNext(true), false, true);
            fm->setCursorPosition(getNext(true), false, true);
            char pChar = ' ';
            char c = ' ';
            while(fm->cursorPosition != prev) {
                prev = fm->cursorPosition;
                pChar = c;
                c = fm->getCharAtCursor();
                if (pChar == '*' && c == '/') {
                    fm->setCursorPosition(original, false, true);
                    return prev;
                }
                fm->setCursorPosition(getNext(true), false, true);
            }
            fm->setCursorPosition(original, false, true);
            return original;
        }
        else if (fm->curLineIter->substr(i,2) == "*/") {
            prev.setCol(i);
            fm->setCursorPosition(prev, false, true);
            fm->setCursorPosition(getPrev(true), false, true);
            char c = ' ';
            char pChar = ' ';
            while(fm->cursorPosition != prev) {
                prev = fm->cursorPosition;
                pChar = c;
                c = fm->getCharAtCursor();
                if (pChar == '*' && c == '/') {
                    fm->setCursorPosition(original, false, true);
                    return prev;
                }
                fm->setCursorPosition(getPrev(true), false, true);
            }
            fm->setCursorPosition(original, false, true);
            return original;
        }
    }

    prev = original;
    prev.setCol(0);
    fm->setCursorPosition(prev, true, true);
    std::string s = fm->curLineIter->substr(0,6);
    if (s.find("#if") == 0
        || s.find("#elif") == 0
        || s.find("#else") == 0) {
        int count = 1;
        fm->moveCursorPosition(0,1,true);
        while (fm->cursorPosition != prev) {
            prev = fm->cursorPosition;
            s = fm->curLineIter->substr(0,6);
            if (count == 1 &&
                (s.find("#elif") == 0
                || s.find("#else") == 0
                || s.find("#endif") == 0)) {
                fm->setCursorPosition(original, false, true);
                return prev;
            }
            if (s.find("#if") == 0) ++count;
            else if (s.find("#endif") == 0) --count;
            fm->moveCursorPosition(0,1,true);
        }
        fm->setCursorPosition(original, false, true);
        return original;
    }
    else if (fm->curLineIter->find("#endif") == 0) {
        int count = 1;
        fm->moveCursorPosition(0,-1,true);
        while (fm->cursorPosition != prev) {
            prev = fm->cursorPosition;
            s = fm->curLineIter->substr(0,6);
            if (count == 1 && s.find("#if") == 0) {
                fm->setCursorPosition(original, false, true);
                return prev;
            }
            if (s.find("#if") == 0) --count;
            else if (s.find("#endif") == 0) ++count;
            fm->moveCursorPosition(0,-1,true);
        }
        fm->setCursorPosition(original, false, true);
        return original;
    }
    fm->setCursorPosition(original, false, true);
    return original;
}
