#include "multiline.hpp"
#include "graphics.hpp"
#include "application.hpp"
#include <sstream>
#include <fstream>

using namespace std;
using namespace genv;

MultiLine::MultiLine(Application *app, int x_, int y_, int w_, int sorok_, const std::string &szoveg_file)
    : Widget(app, x_, y_, w_, (gout.cascent()+gout.cdescent()+2)*sorok_), mutatott_sorok(sorok_), legfelso(0)
{
    load(szoveg_file);
}

void MultiLine::load(const std::string &fname)
{
    ifstream f(fname);
    stringstream sor;
    int sor_hossz = 0;
    while(f.good())
    {
        string szo;
        f >> szo;
        int szo_hossz = gout.twidth(szo) + gout.twidth(" ");
        if (sor_hossz + szo_hossz > _size_x-15)
        {
            sorok.push_back(sor.str());
            sor.str("");
            sor_hossz = 0;
        }
        sor << szo << ' ';
        sor_hossz += szo_hossz;
    }
    f.close();

    sorok.push_back(sor.str());
}

void MultiLine::gorget(int d)
{
    if (int(sorok.size()) > mutatott_sorok)
    {
        legfelso += d;
        legfelso = min(legfelso, int(sorok.size()-1));
        legfelso = max(legfelso, 0);
    }
}

void MultiLine::handle(event ev)
{
    if (ev.type == ev_mouse)
    {
        if (ev.button == btn_wheelup)
        {
            gorget(-1);
        }
        if (ev.button == btn_wheeldown)
        {
            gorget(+1);
        }
    }
}

void MultiLine::draw()
{
    gout << color(255,255,255) << move_to(_x, _y) << box(_size_x, _size_y);
    gout << color(0,0,0);
    int legalso = min(legfelso+mutatott_sorok, int(sorok.size()));
    int sormagassag = gout.cdescent()+gout.cascent()+2;
    for (int i = legfelso; i < legalso; i++)
    {
        if (!sorok[i].empty())
        {
            gout << move_to(_x+5, _y+(i-legfelso)*sormagassag+gout.cascent()) << text(sorok[i]);
        }
    }

    gout << color(150, 150, 150);
    gout << move_to(_x+_size_x-5, _y) << line(0, _size_y);

    float csuszka_h = _size_y / float(sorok.size());
    int csuszka_w = 5;
    int csuszka_x = _x+_size_x-5;
    float csuszka_y = _y+legfelso*csuszka_h;
    gout << move_to(csuszka_x, csuszka_y) << box(csuszka_w, csuszka_h);
}
