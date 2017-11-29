#include "model.h"

Model::Model(std::unique_ptr<Controller> &&control, std::unique_ptr<View> &&view): control{std::move(control)} {
    views.emplace_back(std::move(view));
}

void Model::updateViews(const std::vector<std::string> &buf, Position p) {
    for(auto& view : views) {
        view -> update(buf, p);
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

CommandInfo Model::getCommand(Model *m) {
    return control -> getCommand(m);
}

int Model::getChar() {
    return control->getChar();
}

void Model::updateViewBottomTexts(const std::string &s) {
    for (auto &view: views) {
        view->updateBottomText(s);
    }
}
