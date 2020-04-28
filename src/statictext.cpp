#include "statictext.hpp"
#include "graphics.hpp"
#include <string>

using namespace std;
using namespace genv;

StaticText::StaticText(Application *app, int x, int y, const string &text_)
    : Widget(
        app,
        x, y, 
        genv::gout.twidth(text_), 
        genv::gout.cascent() + genv::gout.cdescent()), 
    text(text_)
{
}

void StaticText::draw()
{
    gout << color(210, 210, 210)
         << move_to(_x, _y+gout.cascent()) 
         << genv::text(text);
}

void StaticText::handle(event ev)
{
    // do nothing
}