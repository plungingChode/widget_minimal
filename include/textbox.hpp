#ifndef TEXTBOX_HPP_INCLUDED
#define TEXTBOX_HPP_INCLUDED

#include "statictext.hpp"

class TextBox : public Widget
{
protected:
    std::string _text;
    bool _selected;

public:
    TextBox(Application *parent, int x, int y, int sx, int sy, const std::string &text);

    std::string get_text() const { return _text; }

    virtual void draw() override;
    virtual void handle(genv::event ev) override;
    virtual bool is_selected(int mouse_x, int mouse_y) override;
};

#endif