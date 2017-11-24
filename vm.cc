#include "vm.h"
#include "curseControl.h"
#include "curseView.h"
#include <iostream>

Vm::Vm(const std::string &fileName): Model(std::make_unique<CurseKeyboard>(), std::make_unique<CurseView>()), running{true}, insertMode{false}, fileManager{fileName}, offset{0}, numLines{20} {
}

void Vm::runVm() {
    std::cout << "running vm..." << std::endl;
    updateViews(fileManager.getLines(offset, numLines));
    std::cout << "displaying views..." << std::endl;
    displayViews();
    insertMode = true;
    runInsertMode();
}

void Vm::runInsertMode() {
    std::cout << "insert mode" << std::endl;
    while(insertMode) {
        char c = getChar();
        if (c == 27) {//escape char
            insertMode = false;
            return;
        }
        std::cout << "char received: " << c << std::endl;
        fileManager.insertChar(c);
        std::cout << "char inserted" << std::endl;
        updateViews(fileManager.getLines(offset, numLines));
        displayViews();
    }
}

void addFootprint() {
    throw;
}

void popFootprint() {
    throw;
}

Footprint getLastFootprint() {
    throw;
}

CommandInfo getPrevCommand() {
    throw;
}
