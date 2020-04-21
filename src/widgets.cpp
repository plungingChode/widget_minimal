#include "widgets.hpp"
#include "graphics.hpp"
#include "application.hpp"

using namespace genv;

Widget::Widget(Application *app, int x, int y, int sx, int sy) : 
    parent(app), _x(x), _y(y), _size_x(sx), _size_y(sy)
{
    app->register_widget(this);
}

bool Widget::is_selected(int mouse_x, int mouse_y) 
{
    return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}






