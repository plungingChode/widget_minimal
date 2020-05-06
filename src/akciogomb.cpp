#include "akciogomb.hpp"
#include "application.hpp"

using namespace std;
using namespace genv;

AkcioGomb::AkcioGomb(Application *app, int x, int y, int w, int h, string felirat_, string akcio_)
    : Widget(app, x, y, w, h), felirat(felirat_), akcio(akcio_), benyomva(false), hitbox(x, y, w, h)
{
}

void AkcioGomb::handle(event ev)
{
    if (ev.type == ev_mouse)
    {
        if (ev.button == btn_left && hitbox.benne(ev.pos_x, ev.pos_y))
        {
            benyomva = true;
        }
        if (ev.button == -btn_left)
        {
            if (hitbox.benne(ev.pos_x, ev.pos_y))
            {
                parent->action(akcio);
            }
            benyomva = false;
        }
    }
    if (ev.type == ev_key)
    {
        if (ev.keycode == key_enter)
        {
            benyomva = true;
        }
        if (ev.keycode == -key_enter)
        {
            benyomva = false;
            parent->action(akcio);
        }
    }
}

void AkcioGomb::draw()
{
    gout << color(255, 255, 255) << move_to(_x, _y) << box(_size_x, _size_y);

    color vilagos = color(150, 150, 150);
    color sotet = color(50, 50, 50);
    if (!benyomva)
    {
        gout << vilagos;
        gout << move_to(_x, _y) << line(0, _size_y);
        gout << move_to(_x, _y) << line(_size_x, 0);

        gout << sotet;
        gout << move_to(_x+_size_x, _y+_size_y) << line(0, -_size_y);
        gout << move_to(_x+_size_x, _y+_size_y) << line(-_size_x, 0);
    }
    else
    {
        gout << vilagos;
        gout << move_to(_x+_size_x, _y+_size_y) << line(0, -_size_y);
        gout << move_to(_x+_size_x, _y+_size_y) << line(-_size_x, 0);

        gout << sotet;
        gout << move_to(_x, _y) << line(0, _size_y);
        gout << move_to(_x, _y) << line(_size_x, 0);
    }

    gout << color(0, 0, 0);
    gout << move_to(_x+_size_x/2, _y+_size_y/2) 
         << genv::move(-gout.twidth(felirat)/2, 5);
    if (benyomva)
    {
        gout << genv::move(1, 1);
    }
    gout << text(felirat);
}