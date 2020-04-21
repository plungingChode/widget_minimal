#include "szambeall.hpp"

using namespace std;
using namespace genv;

Szambeall::Szambeall(Application *app, int x, int y, int w, int h, int szam_, int also_hat_, int felso_hat_)
    : Widget(app, x, y, w, h), szam(szam_), also_hat(also_hat_), felso_hat(felso_hat_), 
      fel_gomb(x+w-12, y, 12, h/2), le_gomb(x+w-12, y+h/2, 12, h/2)
{
}

void Szambeall::szam_valt(int d)
{
    szam = max(min(szam+d, felso_hat), also_hat);
}

void Szambeall::handle(event ev)
{
    if (ev.type == ev_mouse)
    {
        if (ev.button == btn_left)
        {
            if (fel_gomb.benne(ev.pos_x, ev.pos_y))
            {
                szam_valt(+1);
            }
            if (le_gomb.benne(ev.pos_x, ev.pos_y))
            {
                szam_valt(-1);
            }
        }
        if (ev.button == btn_wheelup)
        {
            szam_valt(+1);
        }
        if (ev.button == btn_wheeldown)
        {
            szam_valt(-1);
        }
    }

    if (ev.type == ev_key)
    {
        switch(ev.keycode)
        {
        case key_up: szam_valt(+1); break;
        case key_down: szam_valt(-1); break;
        case key_pgup: szam_valt(+10); break;
        case key_pgdn: szam_valt(-10); break;
        }
    }
}

void Szambeall::draw()
{
    gout << move_to(_x, _y) << color(255, 255, 255) << box(_size_x, _size_y);
    gout << color(0, 0, 0);
    gout << move_to(fel_gomb.x, _y) << line(0, _size_y);
    gout << move_to(fel_gomb.x, le_gomb.y) << line(fel_gomb.w, 0);

    gout << move_to(fel_gomb.x + fel_gomb.w/2, fel_gomb.y + fel_gomb.h/2)
         << genv::move(-3, 5)
         << text('+');

    gout << move_to(le_gomb.x + le_gomb.w/2, le_gomb.y + le_gomb.h/2)
         << genv::move(-3, 5)
         << text('-');
    
    gout << move_to(_x+5, _y+5+gout.cascent()) << text(to_string(szam));
}

