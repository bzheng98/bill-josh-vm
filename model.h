#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>
#include "controller.h"
#include "view.h"
#include "commandInfo.h"
#include "observer.h"
#include <memory>

enum CommandType;

class Model {
    std::vector<std::unique_ptr<View>> views;
    std::unique_ptr<Controller> control;
  protected:
    void addView(std::unique_ptr<View> v);
    void addController(std::unique_ptr<Controller> v);
  public:
    Model(std::unique_ptr<Controller> &&control, std::unique_ptr<View> &&view);
    virtual ~Model() = default;
    void updateViews(const std::vector<std::string> &buf, Position p);
    void updateViewCursors(Position p);
    void updateViewBottomTexts(const std::string &s);
    int getChar();
    CommandInfo getCommand(Model *m);
    void displayViews();
};
#endif
