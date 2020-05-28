#ifndef TLISTA_HPP_INCLUDED
#define TLISTA_HPP_INCLUDED

#include "widgets.hpp"
#include "teglalap.hpp"
#include <vector>

using namespace genv;

// barmilyen T tipust elfogad, aminek van 
// std::string str(); tagfuggvenye
template<typename T>
class TLista : public Widget
{
protected:
    std::vector<T> elemek;
    std::vector<teglalap> elem_helyek;
    int sorok;
    int legfelso;
    int kijelolt;

public:
    TLista(Application *app, int x, int y, int w, int sorok_, std::vector<T> elemek_)
        : Widget(app, x, y, w, (gout.cascent()+gout.cdescent())*sorok_), 
          elemek(elemek_), sorok(sorok_), legfelso(0), kijelolt(-1)
    {
        int sormagassag = gout.cascent()+gout.cdescent();
        for (int i = 0; i < sorok_; i++)
        {
            teglalap t(_x, _y+i*sormagassag, _size_x-5, sormagassag);
            elem_helyek.push_back(t);
        }
    }

    void gorget(int d)
    {
        if (int(elemek.size()) > sorok)
        {
            legfelso += d;
            legfelso = std::min(legfelso, int(elemek.size()-sorok));
            legfelso = std::max(legfelso, 0);
        }
    }

    void kijelolest_mozgat(int i)
    {
        kijelolt = std::min(std::max(kijelolt+i, 0), int(elemek.size()-1));
        if (kijelolt >= legfelso+sorok)
        {
            gorget(+1);
        }
        if (kijelolt < legfelso)
        {
            gorget(-1);
        }
    }

    const T* ertek() const 
    { 
        if (kijelolt != -1) { return &elemek[kijelolt]; } 
        else { return nullptr; } 
    }

    int kijelolt_index() const { return kijelolt; }

    void hozzaad(T elem) { elemek.push_back(elem); }

    void torol(int index)
    {
        elemek.erase(elemek.begin()+index);
        if (legfelso >= int(elemek.size())-sorok)
        {
            legfelso = std::max(legfelso-1, 0);
        } 
        if (kijelolt == index)
        {
            kijelolt = -1;
        }
    }

    void lecserel(std::vector<T> uj_elemek) { elemek = uj_elemek; }
    void lecserel(int index, T uj_elem) { elemek[index] = uj_elem; }

    virtual void handle(genv::event ev) override
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
            if (ev.button == btn_left)
            {
                for (size_t i = 0; i < elem_helyek.size(); i++)
                {
                    if (elem_helyek[i].benne(ev.pos_x, ev.pos_y))
                    {
                        kijelolt = legfelso+i;
                        break;
                    }
                }
            }
        }

        if (ev.type == ev_key)
        {
            if (ev.keycode == key_up)
            {
                kijelolest_mozgat(-1);
            }
            if (ev.keycode == key_down)
            {
                kijelolest_mozgat(+1);
            }
        }
    }

    virtual void draw() override
    {
        gout << move_to(_x, _y) << color(255, 255, 255) << box(_size_x, _size_y);

        gout << color(0, 0, 0);
        int legalso = std::min(legfelso+sorok, int(elemek.size()));

        int poz = 0;
        for (int i = legfelso; i < legalso; i++)
        {   
            teglalap t = elem_helyek[poz];
            gout << move_to(t.x, t.y);
            if (i == kijelolt)
            {
                gout << color(90, 90, 200) << box(t.w, t.h);
                gout << color(255, 255, 255) << move_to(t.x, t.y);
            }
            else
            {
                gout << color(0, 0, 0);
            }

            // emiatt tud kiirni barmit + nem fordul le, ha T-nek nincs
            // .str() fuggvenye 
            gout << move(5, gout.cascent()) << text(elemek[i].str());
            ++poz;
        }

        gout << color(150, 150, 150);
        gout << move_to(_x+_size_x-5, _y) << line(0, _size_y);

        float csuszka_h = _size_y / float(elemek.size()-(sorok-1));
        int csuszka_w = 5;
        int csuszka_x = _x+_size_x-5;
        float csuszka_y = _y+legfelso*csuszka_h;
        gout << move_to(csuszka_x, csuszka_y) << box(csuszka_w, csuszka_h);
    }
};

#endif
