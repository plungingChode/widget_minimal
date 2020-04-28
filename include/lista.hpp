#ifndef LISTA_HPP_INCLUDED
#define LISTA_HPP_INCLUDED

#include "widgets.hpp"
#include "teglalap.hpp"
#include <vector>

class Lista : public Widget
{
protected:
    std::vector<std::string> elemek;
    std::vector<teglalap> elem_helyek;
    int sorok;
    int legfelso;
    int kijelolt;

public:
    Lista(Application *app, int x, int y, int w, int sorok, std::vector<std::string> elemek);

    void gorget(int d);
    void kijelolest_mozgat(int i); // nem kotelezo

    std::string ertek() const { if (kijelolt != -1) return elemek[kijelolt]; }
    int kijelolt_index() const { return kijelolt; }

    void hozzaad(std::string elem) { elemek.push_back(elem); }
    void torol(int index);
    void lecserel(std::vector<std::string> uj_elemek) { elemek = uj_elemek; }

    virtual void handle(genv::event ev) override;
    virtual void draw() override;
};


#endif