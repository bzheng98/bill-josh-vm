#include "vm.h"
#include "curseControl.h"
#include "curseView.h"
#include <fstream>
#include "all_commands.h"
#include "keys.h"

Vm::Vm(const std::string &fileName): Model(std::make_unique<CurseKeyboard>(), std::make_unique<CurseView>()), running{true}, insertMode{false}, fileManager{fileName}, registerManager{}, footprints{}, offset{0}, numLines{20} {
   attach(std::make_unique<Up>(this, &fileManager, &registerManager));
   attach(std::make_unique<Down>(this, &fileManager, &registerManager));
   attach(std::make_unique<Left>(this, &fileManager, &registerManager));
   attach(std::make_unique<Right>(this, &fileManager, &registerManager));
   attach(std::make_unique<Insert>(this, &fileManager, &registerManager));
   attach(std::make_unique<Write>(this, &fileManager, &registerManager));
   attach(std::make_unique<Quit>(this, &fileManager, &registerManager));
   attach(std::make_unique<WriteQuit>(this, &fileManager, &registerManager));
}

void Vm::runVm() {
    while(running) {
        updateViews(fileManager.getLines(offset, numLines), fileManager.getCursorPosition());
        log("updateviews");
        updateViewCursors(fileManager.getCursorPosition());
        log("update cursors");
        displayViews();

        CommandInfo info = getCommand(this);
        notifyObservers(info);
    }
}

void Vm::runInsertMode() {
    insertMode = true;
    updateViewBottomTexts("-- INSERT --");
    log("insert mode");
    while(insertMode) {
        updateViews(fileManager.getLines(offset, numLines), fileManager.getCursorPosition());
        updateViewCursors(fileManager.getCursorPosition());
        displayViews();
        log("getting input");
        int c = getChar();
        log(c);
        if (is_escape(c)) {//escape char
            insertMode = false;
            updateViewBottomTexts("");
            break;
        }
        else if (is_left(c)) {
            fileManager.moveCursorPosition(-1,0,true);
        }
        else if (is_right(c)) {
            fileManager.moveCursorPosition(1,0,true);
        }
        else if (is_up(c)) {
            fileManager.moveCursorPosition(0,-1,true);
        }
        else if (is_down(c)) {
            fileManager.moveCursorPosition(0,1,true);
        }
        else if (is_backspace(c)) {
            fileManager.deleteChar();
        }
        else fileManager.insertChar(c);
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

void Vm::quit() {
    running = false;
}

template<typename T> void Vm::log(T s) {
    logger << s << std::endl;
}
