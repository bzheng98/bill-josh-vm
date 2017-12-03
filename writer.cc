#include "writer.h"
#include "fileManager.h"

void Writer::save(const std::string &s) {
    fileManager->saveFile(s);
}
