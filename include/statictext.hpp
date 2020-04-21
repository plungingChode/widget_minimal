#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED

#include "widgets.hpp"

class StaticText : public Widget
{
protected:
    std::string text;

public:
    StaticText(Application *parent, int x, int y, const std::string &text);

    virtual void draw() override;
    virtual void handle(genv::event ev) override;
};

#endif  