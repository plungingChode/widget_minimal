#include "statictext.hpp"
#include "graphics.hpp"
#include <string>

using namespace std;
using namespace genv;

StaticText::StaticText(Application *app, int x, int y, const string &text)
    : Widget(
        app,
        x, y, 
        genv::gout.twidth(text), 
        genv::gout.cascent() + genv::gout.cdescent()), 
    text(text)
{
}

void StaticText::draw()
{
    gout << move_to(_x, _y+gout.cascent()) 
         << genv::text(text);
    // gout << move_to(_x, _y) << color(255, 0, 0)
    //      << line(0, _size_y) << line(_size_x, 0)
    //      << line(0, -_size_y) << line(-_size_x, 0);
}

void StaticText::handle(event ev)
{
    // do nothing
}