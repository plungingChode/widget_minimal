#ifndef KIJELZO_HPP_INCLUDED
#define KIJELZO_HPP_INCLUDED

#include "textbox.hpp"

class Kijelzo : public TextBox
{
public:
    using TextBox::TextBox;

    void add_digit(int d);
    void set_number(int d);
    void set_text(const std::string &str);
    void clear();

    virtual void draw() override;
    virtual void handle(genv::event ev) override;
    virtual bool is_selected(int mouse_x, int mouse_y) override;
};



#endif