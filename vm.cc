#include "vm.h"
#include "curseControl.h"
#include "curseView.h"
#include <fstream>
#include "all_commands.h"
#include "keys.h"
#include "motionCommand.h"
Vm::Vm(const std::string &fileName): Model(std::make_unique<CurseKeyboard>(), std::make_unique<CurseView>()), running{true}, fileManager{fileName}, registerManager{}, footprints{}, offset{0}, numLines{100}, motionCommands{
        new Up{this, &fileManager, &registerManager},
        new Down{this, &fileManager, &registerManager},
        new Left{this, &fileManager, &registerManager},
        new Right{this, &fileManager, &registerManager},
        new WordForward{this, &fileManager, &registerManager},
        new WordBack{this, &fileManager, &registerManager},
        new FindForward{this, &fileManager, &registerManager},
        new FindBack{this, &fileManager, &registerManager},
        new LineBegin{this, &fileManager, &registerManager},
        new LineEnd{this, &fileManager, &registerManager},
        new LineJump{this, &fileManager, &registerManager},
        new JumpToMatch{this, &fileManager, &registerManager},
        new SearchForward{this, &fileManager, &registerManager},
        new SearchBack{this, &fileManager, &registerManager}
        } {
    attach(std::make_unique<Insert>(this, &fileManager, &registerManager));
    attach(std::make_unique<Append>(this, &fileManager, &registerManager));
    attach(std::make_unique<Prepend>(this, &fileManager, &registerManager));
    attach(std::make_unique<NewlineInsert>(this, &fileManager, &registerManager));
    attach(std::make_unique<AppendToLine>(this, &fileManager, &registerManager));
    attach(std::make_unique<EnterReplaceMode>(this, &fileManager, &registerManager));
    attach(std::make_unique<Write>(this, &fileManager, &registerManager));
    attach(std::make_unique<Quit>(this, &fileManager, &registerManager));
    attach(std::make_unique<WriteQuit>(this, &fileManager, &registerManager));
    attach(std::make_unique<Undo>(this, &fileManager, &registerManager));
    attach(std::make_unique<Delete>(this, &fileManager, &registerManager));
    attach(std::make_unique<ScrollUp>(this, &fileManager, &registerManager));
    attach(std::make_unique<ScrollDown>(this, &fileManager, &registerManager));
    attach(std::make_unique<ScrollForward>(this, &fileManager, &registerManager));
    attach(std::make_unique<ScrollBackward>(this, &fileManager, &registerManager));
    attach(std::make_unique<Yank>(this, &fileManager, &registerManager));
    attach(std::make_unique<Paste>(this, &fileManager, &registerManager));
    attach(std::make_unique<ReplaceChar>(this, &fileManager, &registerManager));
    attach(std::make_unique<ReplaceMotion>(this, &fileManager, &registerManager));
    attach(std::make_unique<ForceQuit>(this, &fileManager, &registerManager));
    attach(std::make_unique<NextSearch>(this, &fileManager, &registerManager));
	
    for (const auto &commandPtr: motionCommands)
        attach(std::unique_ptr<Command>(commandPtr));
}

void Vm::runVm() {
    while(running) {
    	log("running");
		updateViews(fileManager.getLines(offset, numLines), fileManager.getCursorPosition());
        log("updated");
		updateViewCursors(fileManager.getCursorPosition());
        displayViews();

        CommandInfo info = getCommand(this);
        notifyObservers(info);
    }
}

std::string Vm::runInsertMode(std::string &inserted, bool replace) {
    bool motionUsed = false;
    if (replace) {
        updateViewBottomTexts("-- REPLACE --");
        log("replace mode");
    }
    else {
        updateViewBottomTexts("-- INSERT --");
        log("insert mode");
    }
    std::vector<int> replaced;
    while(true) {
        updateViews(fileManager.getLines(offset, numLines), fileManager.getCursorPosition());
        updateViewCursors(fileManager.getCursorPosition());
        displayViews();
        log("getting input");
        int c = getChar();
        log(c);
        if (is_escape(c)) {//escape char
            updateViewBottomTexts("");
            break;
        }
        else if (is_left(c)) {
            motionUsed = true;
            fileManager.moveCursorPosition(-1,0,true);
            if (replace) replaced.clear();
        }
        else if (is_right(c)) {
            motionUsed = true;
            fileManager.moveCursorPosition(1,0,true);
            if (replace) replaced.clear();
        }
        else if (is_up(c)) {
            motionUsed = true;
            fileManager.moveCursorPosition(0,-1,true);
            if (replace) replaced.clear();
        }
        else if (is_down(c)) {
            motionUsed = true;
            fileManager.moveCursorPosition(0,1,true);
            if (replace) replaced.clear();
        }
        else if (is_backspace(c)) {
            if (replace) {
                if (replaced.size()) {
                    int lastReplaced = replaced.back();
                    if (lastReplaced != -1) {
                        fileManager.insertChar((char)replaced.back());
                        fileManager.moveCursorBack();
                    }
                    replaced.pop_back();
                } else {
                    motionUsed = true;
                    fileManager.moveCursorBack();
                }
                if (!motionUsed && inserted.size())
                    inserted.pop_back();
            }
            else {
                int del = fileManager.deleteChar();
                if (inserted.size())
                    inserted.pop_back();
                else {
                    replaced.push_back(del);
                }
            }
        }
        else {
            if (!motionUsed)
                inserted.push_back(c);
            if (replace)
                replaced.push_back(fileManager.replaceChar(c));
            else {
                fileManager.insertChar(c);
            }
        }
    }
    std::string ret;
    if (replace) {
        for (int i = 0; i < replaced.size(); ++i)
            if (replaced[i] != -1) ret.push_back((char)replaced[i]);
    }
    else
        for (int i = replaced.size()-1; i >= 0; --i)
            if (replaced[i] != -1) ret.push_back((char)replaced[i]);
    return ret;
}

void Vm::addFootprint(std::unique_ptr<Footprint> &&f) {
    footprints.push_back(std::move(f));
}

void Vm::popLastFootprint() {
    footprints.pop_back();
    if (footprints.size() < lastFootprint)
        lastFootprint = 2e9;
}

Footprint &Vm::getLastFootprint() {
    log("FOOTPRINTS");
    log(footprints.size());
    return *footprints.back();
}

void Vm::quit() {
    running = false;
}

bool Vm::hasFootprint() {
    return !footprints.empty();
}

Range Vm::getMotion(const CommandInfo &c) {
    for (auto &commandPtr: motionCommands) {
        if (commandPtr->checkCommand(c)) {
            Position end = commandPtr->getMotionResult(c);
            if (end.getLine() == -1) return Range{fileManager.getCursorPosition(), fileManager.getCursorPosition()};
            Range ret = {fileManager.getCursorPosition(), end};
            log("Range found:");
            log(ret.getStart().getCol());
            log(ret.getEnd().getCol());
            if (commandPtr->isLinewise()) {
                ret.makeLinewise();
            }
            return ret;
        }
    }
}

Position Vm::getViewCursor() {
	return views[0] -> getCursor();
}

bool Vm::isWritten() {
    return footprints.size() == lastFootprint;
}

void Vm::write(std::string fileName) {
    if (!fileName.length())
        fileName = fileManager.getFileName();
    updateViewBottomTexts("\""+fileName+"\" "+std::to_string(fileManager.getNumLines())+"L, "+std::to_string(fileManager.getNumChars())+"C written");  
    
    lastFootprint = footprints.size();
}

void Vm::storeLastSearch(const std::string &s, bool forward) {
    if (!nextSearch)
        searchForward = forward;
    else --nextSearch;
    lastSearch = s;
}

const std::string &Vm::getLastSearch() {
    return lastSearch;
}

bool Vm::getLastSearchDir() {
    return searchForward;
}

void Vm::nextSearchUsed(int count) {
    nextSearch = count;
}
