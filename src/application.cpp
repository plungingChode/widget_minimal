#include "application.hpp"
#include "graphics.hpp"

using namespace genv;

void Application::event_loop()
{
    for (Widget * w : widgets) {
        w->draw();
    }
    gout << refresh;

    event ev;
    int focus = -1;
    while(gin >> ev ) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        for (Widget * w : widgets) {
            w->draw();
        }
        if (ev.keycode == key_enter)
        {
            action("enter");
        }
        gout << refresh;
    }
}