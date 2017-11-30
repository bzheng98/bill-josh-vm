#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>
#include "controller.h"
#include "view.h"
#include "commandInfo.h"
#include "observer.h"
#include <memory>
#include <fstream>
#include <iostream>

enum CommandType;

class Model {
    std::vector<std::unique_ptr<View>> views;
    std::unique_ptr<Controller> control;
    std::ofstream logger{"log.txt"};
  protected:
    void addView(std::unique_ptr<View> v);
    void addController(std::unique_ptr<Controller> v);
  public:
    Model(std::unique_ptr<Controller> &&control, std::unique_ptr<View> &&view);
    virtual ~Model() = default;
    void updateViews(const std::vector<std::string> &buf);
    void updateViewCursors(Position p);
    void updateViewBottomTexts(const std::string &s);
    int getChar();
    CommandInfo getCommand(Model *m);
    void displayViews();
    template<typename T> void log(T s) {
        logger << s << std::endl;
    }
};
#endif
