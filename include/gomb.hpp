#ifndef GOMB_HPP_INCLUDED
#define GOMB_HPP_INCLUDED

#include "widgets.hpp"
#include "teglalap.hpp"
#include <functional>

class Gomb : public Widget
{
protected:
    std::string felirat;
    std::function<void()> akcio;
    bool benyomva;
    teglalap hitbox;

public:
    Gomb(Application *app, int x, int y, int w, int h, std::string felirat, std::function<void()> akcio);
 
    void handle(genv::event ev) override;
    void draw() override;
};

#endif