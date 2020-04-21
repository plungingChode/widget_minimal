#include "textbox.hpp"
#include "graphics.hpp"

using namespace std;
using namespace genv;

TextBox::TextBox(Application *app, int x, int y, int sx, int sy, 
                 const std::string &text)
    : Widget(app, x, y, sx, sy), 
      _text(text), _selected(false)
{
}

void TextBox::draw()
{
    gout << move_to(_x, _y) 
         << color(255, 100, 100) << box(_size_x, _size_y)
         << move_to(_x+1, _y+1)
         << color(255, 255, 255) << box(_size_x-2, _size_y-2);

    gout << color(0, 0, 0);   
    gout << move_to(_x+5, _y+5+gout.cascent()) 
         << text(_text);

    if (_selected)
    {
        gout << move_to(_x+5+gout.twidth(_text)+1, _y+5)
             << line(0, gout.cascent() + gout.cdescent());
    }
}

bool TextBox::is_selected(int mx, int my)
{
    _selected = Widget::is_selected(mx, my);
    return _selected;
}

void TextBox::handle(event ev)
{
    if (_selected && ev.type == ev_key)
    {
        if (ev.keycode >= 32 && ev.keycode < 256)
        {
            _text += ev.keycode;
        }

        if (ev.keycode == key_backspace && _text.length() > 0)
        {
            _text.pop_back();
        }
    }
}