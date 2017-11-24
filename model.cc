#include "model.h"

void Model::updateViews(const std::vector<std::string> &buf) {
    for(auto& view : views) {
        view -> update(buf);
    }
}

void Model::updateViewCursors(Position p) {
    for(auto& view : views) {
        view -> updateCursor(p);
    }
}

void Model::displayViews() {
    for(auto& view : views) {
        view -> updateView();
    }
}

void Model::addView(std::unique_ptr<View> v) {
    views.emplace_back(std::move(v));
}

void Model::addController(std::unique_ptr<Controller> c) {
    control = std::move(c);
}

CommandInfo Model::getCommand() {
    return control -> getCommand();
}

char Model::getChar() {
    return control->getChar();
}
