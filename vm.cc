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
}

void Vm::runVm() {
    /*
   // std::cout << "running vm..." << std::endl;
    updateViews(fileManager.getLines(offset, numLines));
  //  std::cout << "displaying views..." << std::endl;
    displayViews();
    insertMode = true;
    runInsertMode();
    */
    Right r(this, &fileManager, nullptr);
    while(true) {
        updateViews(fileManager.getLines(offset, numLines));
        updateViewCursors(fileManager.getCursorPosition());
        displayViews();

        CommandInfo info = getCommand();
        /*CommandType type = info.getCommandType();
        if(type == RIGHT)
        {
            //std::cout << "here\n";
            r.update(info);
        }*/
        notifyObservers(info);
    }
}


void Vm::runInsertMode() {
    // std::cout << "insert mode" << std::endl;
    insertMode = true;
    while(insertMode) {
        char c = getChar();
        if (c == 27) {//escape char
            insertMode = false;
            return;
        }
        fileManager.insertChar(c);
        updateViews(fileManager.getLines(offset, numLines));
        updateViewCursors(fileManager.getCursorPosition());
        displayViews();
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
