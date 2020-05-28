#include "graphics.hpp"
#include "widgets.hpp"
#include "examplecheckbox.hpp"
#include "statictext.hpp"
#include "textbox.hpp"
#include "application.hpp"
#include "szambeall.hpp"
#include "tlista.hpp"
#include "gomb.hpp"
#include "multiline.hpp"
#include <vector>
#include <fstream>

using namespace std;
using namespace genv;

struct Vmi 
{
    int id;
    string text;

    string str() { return '[' + std::to_string(id) + "] " + text; }
};

class MyApp : public Application
{
protected:
    StaticText *tb_label, *sz_label, *lis_label, *ml_label;
    TextBox *fnev, *tart;
    Szambeall *szb1, *szb2;
    TLista<Vmi> *lis1, *lis2;
    Gomb *g1, *g2;
    MultiLine *tb;

public:
    MyApp() 
    {
        tb_label = new StaticText(this, 30, 10, "szovegdoboz");
        fnev = new TextBox(this, 30, 30, 100, 25, "text 1");
        tart = new TextBox(this, 30, 60, 100, 25, "text 2");

        sz_label = new StaticText(this, 30, 90, "szambeallito");
        szb1 = new Szambeall(this, 30, 110, 50, 25, 5, 0, 15);
        szb2 = new Szambeall(this, 30, 140, 50, 25, -5, -99, 0);
        
        lis_label = new StaticText(this, 150, 10, "lista");

        vector<Vmi> v1 = {{1, "a"}, {2, "b"}};
        vector<Vmi> v2 = {{3, "c"}, {4, "d"}, {5, "e"}, {6, "f"}, {7, "g"}};

        lis1 = new TLista<Vmi>(this, 150, 30, 100, 5, v1);
        lis2 = new TLista<Vmi>(this, 260, 30, 100, 3, v2);

        g1 = new Gomb(this, 150, 120, 100, 30, "nyomj meg!", [&](){ g1_akcio(); });
        g2 = new Gomb(this, 150, 155, 100, 30, "engem is!", [&](){ g2_akcio(); });

        ml_label = new StaticText(this, 370, 10, "tobbsoros szoveg");
        tb = new MultiLine(this, 370, 30, 250, 10, "vmi.txt");
    }

    void g1_akcio()
    {
        lis1->hozzaad({100, fnev->get_text()});
    }

    void g2_akcio()
    {
        int index = lis1->kijelolt_index();
        if (index != -1)
        {
            lis1->torol(index);
        }
    }
 
    void action(std::string ev) 
    {
        if (ev == "enter")
        {
            std::ofstream f(fnev->get_text());
            f << tart->get_text();
            f.close();
        }

        if (ev == "g1_akcio")
        {
            g1_akcio();
        }
        if (ev == "g2_akcio")
        {
            g2_akcio();
        }
    }
};

int main()
{
    gout.open(640,480);
    // gout.load_font("LiberationSans-Regular.ttf");
    gout << move_to(0, 0) << color(60, 60, 60) << box(640, 480);

    MyApp app;
    app.event_loop();

    return 0;
}
