#ifndef GOMB_HPP_INCLUDED
#define GOMB_HPP_INCLUDED

#include "widgets.hpp"
#include "teglalap.hpp"

class AkcioGomb : public Widget
{
protected:
    std::string felirat, akcio;
    bool benyomva;
    teglalap hitbox;

public:
    AkcioGomb(Application *app, int x, int y, int w, int h, std::string felirat, std::string akcio);
 
    void handle(genv::event ev) override;
    void draw() override;
};

#endif