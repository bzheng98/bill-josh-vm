#include "writer.h"

void Writer::save() {
    fileManager->saveFile();
}

void Writer::update(const CommandInfo &c) {}
