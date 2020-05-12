#include "application.hpp"
#include "gomb.hpp"
#include "kijelzo.hpp"
#include <vector>
#include "graphics.hpp"
#include <cmath>
#include <sstream>

using namespace genv;

class Szamologep : public Application
{
    enum muvelet_t
    {
        nincs = 0,
        osszeadas,
        kivonas,
        szorzas,
        osztas,
        egyenlo
    };

    Kijelzo *kijelzo;
    Gomb *plusz, *minusz, *szor, *per, *egyen, *clr;
    std::vector<Gomb*> szam_gombok = std::vector<Gomb*>(10);

    std::vector<int> szamjegyek;
    int szam1 = 0;
    int ans = 0;
    muvelet_t muvelet = nincs;

public:
    Szamologep()
    {
        kijelzo = new Kijelzo(this, 20, 10, 200, 30, "0");

        plusz = new Gomb(this, 150, 50, 30, 30, "+", [&](){ set_opcode(osszeadas); });
        minusz = new Gomb(this, 150, 90, 30, 30, "-", [&](){ set_opcode(kivonas); });
        szor = new Gomb(this, 150, 130, 30, 30, "*", [&](){ set_opcode(szorzas); });
        per = new Gomb(this, 150, 170, 30, 30, "/", [&](){ set_opcode(osztas); });
        egyen = new Gomb(this, 190, 50, 30, 110, "=", [&](){ get_ans(); });
        clr = new Gomb(this, 190, 170, 30, 30, "C", [&](){ clear(); });

        for (int i = 0; i < 9; i++)
        {
            int x = 20 + (i%3) * 40;
            int y = 50 + (i/3) * 40;
            int num = i+1;
            std::string felirat = std::to_string(num);
            szam_gombok[i] = new Gomb(this, x, y, 30, 30, felirat, [=](){ add_digit(num); });
        }

        szam_gombok[0] = new Gomb(this,  60, 170, 30, 30, "0", [&](){ add_digit(0); });
    }

    int get_number()
    {
        int szam = 0;
        int cnt = 0;
        auto rit = szamjegyek.rbegin();
        for (; rit != szamjegyek.rend(); ++rit)
        {
            szam += *rit * std::pow(10, cnt);
            ++cnt;
        }
        szamjegyek.clear();
        return szam;
    }

    void clear()
    {
       kijelzo->clear();
       szamjegyek.clear();
    }

    void get_ans()
    {
        int szam2 = get_number();
        switch(muvelet)
        {
        case osszeadas: ans = szam1+szam2; break;
        case kivonas: ans = szam1-szam2; break;
        case szorzas: ans = szam1*szam2; break;
        case osztas: 
            if (szam2 == 0)
            {
                kijelzo->set_text("Nullaval osztas");
                ans = 0;
                muvelet = egyenlo;
                return;
            }
            ans = szam1/szam2; 
            break;
        default: ans = szam1; break;
        }
        muvelet = egyenlo;
        kijelzo->set_number(ans);
    }

    void set_opcode(muvelet_t op)
    {
        szam1 = get_number();
        muvelet = op;
        kijelzo->clear();
    }

    void add_digit(int d)
    {
        if (muvelet == egyenlo)
        {
            kijelzo->clear();
            muvelet = nincs;
        }
        szamjegyek.push_back(d);
        kijelzo->add_digit(d);
    }

    void action(std::string a)
    {
    }

    void run()
    {
        gout.open(240, 220);
        event_loop();
    }
};

int main()
{
    Szamologep s;
    s.run();
    return 0;
}