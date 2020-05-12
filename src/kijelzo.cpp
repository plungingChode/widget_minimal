#include "kijelzo.hpp"

using namespace genv;

void Kijelzo::add_digit(int d)
{
    if (_text[0] == '0')
    {
        _text = "";
    }
    _text += std::to_string(d);
}

void Kijelzo::set_number(int d)
{
    _text = std::to_string(d);
}

void Kijelzo::clear()
{
    set_number(0);
}

void Kijelzo::set_text(const std::string &str)
{
    _text = str;
}

void Kijelzo::draw()
{
    gout << move_to(_x, _y) 
         << color(255, 100, 100) << box(_size_x, _size_y)
         << move_to(_x+1, _y+1)
         << color(255, 255, 255) << box(_size_x-2, _size_y-2);

    gout << color(0, 0, 0);   
    gout << move_to(_x+_size_x-5-gout.twidth(_text), _y+5+gout.cascent()) 
         << text(_text);
}

bool Kijelzo::is_selected(int mx, int my)
{
    _selected = Widget::is_selected(mx, my);
    return _selected;
}

void Kijelzo::handle(event ev)
{
    // if (_selected && ev.type == ev_key)
    // {
    //     if (ev.keycode >= 32 && ev.keycode < 256)
    //     {
    //         _text += ev.keycode;
    //     }

    //     if (ev.keycode == key_backspace && _text.length() > 0)
    //     {
    //         _text.pop_back();
    //     }
    // }
}