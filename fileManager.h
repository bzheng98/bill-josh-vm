#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <string>
#include <list>
#include "position.h"

class FileManager {
    std::list<std::string> lines;
    Position cursorPosition;
  public:
    FileManager(const std::string &fileName);
    const Position &getCursorPosition() const;
    void insertText(const std::string &s, const Position &p);
    void deleteText(const Position &start, const Position &end);
};
#endif
