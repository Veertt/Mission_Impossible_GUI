#include "cgracz.h"
#include "cmapa.h"
#include "Stale.h"

CGracz::CGracz(int x, int y): CObiekt (x,y)
{
}

void CGracz::Wyswietl(QPainter& painter)
{
    SKoordynaty_obiektu koordynaty = Get_koordynaty();
    QPoint p = {koordynaty.K * WIELKOSC_KAFELKA + WIELKOSC_KAFELKA / 2, koordynaty.R * WIELKOSC_KAFELKA + WIELKOSC_KAFELKA / 2};
    QBrush brush(QColor(0,0,255));
    painter.setBrush(brush);
    painter.drawEllipse(p, WIELKOSC_KAFELKA / 2, WIELKOSC_KAFELKA / 2);
}

bool CGracz::czy_mozna_mnie_sledzic()
{
    return true;
}

bool CGracz::czy_mozna_we_mnie_wejsc()
{
    return false;
}

void CGracz::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W)
    {
        qDebug("Tak");
    }
}

Rezultat_Ruchu CGracz::Ruch(CMapa *mapa)
{
    SKoordynaty_obiektu aktualne = Get_koordynaty();

    if(kbhit())
    {
        sterowanie = getch();

        switch(sterowanie)
        {
            case 119:
                aktualne.R--;
                break;

            case 115:
                aktualne.R++;
                break;

            case 100:
                aktualne.K++;
                break;

            case 97:
                aktualne.K--;
                break;
        }
    }

    CObiekt *pom = mapa->Get_co_jest_na_mapie(aktualne.R,aktualne.K);
    Set_koordynaty(aktualne);

    if(pom!=NULL&&pom->czy_za_pomoca_mnie_mozna_wygrac())
    {
        return Wygrana;
    }

    return Nic;
}
