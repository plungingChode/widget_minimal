#ifndef TEXTBLOCK_HPP_INCLUDED
#define TEXTBLOCK_HPP_INCLUDED

#include "widgets.hpp"
#include <vector>

class MultiLine : public Widget
{
protected:
    std::vector<std::string> sorok;
    int mutatott_sorok;
    int legfelso;

public:
    MultiLine(Application *app, int x, int y, int w, int sorok, const std::string &szoveg_file);

    void load(const std::string &fname);
    void gorget(int d);

    void handle(genv::event ev) override;
    void draw() override;
};

#endif