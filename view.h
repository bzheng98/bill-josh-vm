#ifndef VIEW_H
#define VIEW_H

#include <string>
#include <vector>

class View{
public:
    virtual ~View() = default;
    virtual void update(const std::vector<std::string> buf&) = 0;
    virtual void updateView() = 0;
};
#endif
