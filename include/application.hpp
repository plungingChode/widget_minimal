#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "widgets.hpp"
#include <vector>

class Application
{
protected:
    std::vector<Widget*> widgets;

public:
    virtual ~Application() {};

    void event_loop();
    void register_widget(Widget* w) { widgets.push_back(w); }
    virtual void action(std::string e) = 0;
};

#endif
