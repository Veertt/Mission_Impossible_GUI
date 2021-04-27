#include "cmeta.h"
#include "Stale.h"

CMeta::CMeta(int x, int y):CObiekt(x,y)
{
}

Rezultat_Ruchu CMeta::Ruch(CMapa *mapa)
{
    return Nic;
}

void CMeta::Wyswietl(QPainter& painter)
{
    SKoordynaty_obiektu koordynaty = Get_koordynaty();
    QPoint lewyGorny = {koordynaty.K * WIELKOSC_KAFELKA, koordynaty.R * WIELKOSC_KAFELKA};
    QPoint prawyDolny = lewyGorny + QPoint{WIELKOSC_KAFELKA, WIELKOSC_KAFELKA};
    QBrush brush(QColor(0,255,0));
    painter.setBrush(brush);
    painter.drawRect(lewyGorny.x(), lewyGorny.y(), prawyDolny.x(), prawyDolny.y());
}

bool CMeta::czy_za_pomoca_mnie_mozna_wygrac()
{
    return true;
}

