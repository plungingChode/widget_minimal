#ifndef SZAMBEALL_HPP_INCLUDED
#define SZAMBEALL_HPP_INCLUDED

#include "widgets.hpp"
#include "teglalap.hpp"

class Szambeall : public Widget
{
protected:
    int szam;
    int also_hat, felso_hat;
    teglalap fel_gomb, le_gomb;

public:
    Szambeall(Application *app, int x, int y, int w, int h, int szam, int also_hat, int felso_hat);

    void szam_valt(int d);

    int ertek() const { return szam; }

    void handle(genv::event ev) override;
    void draw() override;
};

#endif