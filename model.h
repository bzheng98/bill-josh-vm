#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>
#include "controller.h"
#include "view.h"

enum Commandtype;

class Model {
    std::vector<std::unique_ptr<View>> views;
    std::unique_ptr<Controller> control;
protected:
    void addView(std::unique_ptr<View> v);
    void addController(std::unique_ptr<Controller> v);
public:
    virtual ~Model() = default;
    void updateViews(const std::vector<std::string> buf&);
    CommandType getCommand();
    void displayViews();
};
#endif
