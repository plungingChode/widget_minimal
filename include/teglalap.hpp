#ifndef TEGLALAP_HPP_INCLUDED
#define TEGLALAP_HPP_INCLUDED

struct teglalap
{
    int x, y, w, h;
    teglalap(int x_, int y_, int w_, int h_) : x(x_), y(y_), w(w_), h(h_) {}
    bool benne(int x_, int y_)
    {
        return x_ >= x && x_ <= x+w && y_ >= y && y_ <= y+h;
    }
};

#endif