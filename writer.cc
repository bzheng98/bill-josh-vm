#include "writer.h"
#include "fileManager.h"

void Writer::save() {
    fileManager->saveFile();
}
