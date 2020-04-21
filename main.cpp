#include "graphics.hpp"
#include "widgets.hpp"
#include "examplecheckbox.hpp"
#include "statictext.hpp"
#include "textbox.hpp"
#include "application.hpp"
#include "szambeall.hpp"
#include "lista.hpp"
#include <vector>
#include <fstream>

using namespace std;
using namespace genv;

class MyApp : public Application
{
protected:
    TextBox *fnev, *tart;
    Szambeall *szb;
    Lista *lis;

public:
    MyApp()
    {
        fnev = new TextBox(this, 70, 100, 100, 25, "text 1");
        tart = new TextBox(this, 70, 140, 100, 30, "text 2");
        szb = new Szambeall(this, 70, 180, 50, 30, 5, 0, 15);
        lis = new Lista(this, 200, 100, 100, 5, {"a", "b", "c", "d", "e", "f", "g", "h", "a"});
    }

    void action(std::string ev) 
    {
        if (ev == "enter")
        {
            std::ofstream f(fnev->get_text());
            f << tart->get_text();
            f.close();
        }
    }
};

int main()
{
    gout.open(400,400);

    MyApp app;
    app.event_loop();

    return 0;
}
