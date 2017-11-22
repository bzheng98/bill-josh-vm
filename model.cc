#include "model.h"

void Model::updateViews(std::vector<std::string> buf) {
    for(auto& view : views){
        view -> update(buf);
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

CommandType Model::getCommand() {
    return control -> getCommand();
}
