#include "vm.h"
#include "curseControl.h"
#include "curseView.h"
#include <iostream>
#include "all_commands.h"
Vm::Vm(const std::string &fileName): Model(std::make_unique<CurseKeyboard>(), std::make_unique<CurseView>()), running{true}, insertMode{false}, fileManager{fileName}, registerManager{}, footprints{}, offset{0}, numLines{20} {
   attach(std::make_unique<Up>(this, &fileManager, &registerManager));
   attach(std::make_unique<Down>(this, &fileManager, &registerManager));
   attach(std::make_unique<Left>(this, &fileManager, &registerManager));
   attach(std::make_unique<Right>(this, &fileManager, &registerManager));
   attach(std::make_unique<Insert>(this, &fileManager, &registerManager));
   attach(std::make_unique<Write>(this, &fileManager, &registerManager));
}

void Vm::runVm() {
    while(true) {
        updateViews(fileManager.getLines(offset, numLines));
        updateViewCursors(fileManager.getCursorPosition());
        displayViews();

        CommandInfo info = getCommand(this);
        notifyObservers(info);
    }
}


void Vm::runInsertMode() {
    insertMode = true;
    updateViewBottomTexts("-- INSERT --");
    while(insertMode) {
        updateViews(fileManager.getLines(offset, numLines));
        updateViewCursors(fileManager.getCursorPosition());
        displayViews();       char c = getChar();
        if (c == 27) {//escape char
            insertMode = false;
            return;
        }
        fileManager.insertChar(c);
    }
}

void Vm::addFootprint(std::unique_ptr<Footprint> &&f) {
    footprints.push_back(std::move(f));
}

void Vm::popFootprint() {
    throw;
}

Footprint Vm::getLastFootprint() {
    throw;
}

CommandInfo Vm::getPrevCommand() {
    throw;
}
