#include "csciana.h"
#include "Stale.h"

CSciana::CSciana(int x, int y):CObiekt(x,y)
{

}

Rezultat_Ruchu CSciana::Ruch(CMapa* mapa)
{
    return Nic;
}

void CSciana::Wyswietl(QPainter& painter)
{
    SKoordynaty_obiektu koordynaty = Get_koordynaty();
    QPoint lewyGorny = {koordynaty.K * WIELKOSC_KAFELKA, koordynaty.R * WIELKOSC_KAFELKA};
    QPoint prawyDolny = lewyGorny + QPoint{WIELKOSC_KAFELKA, WIELKOSC_KAFELKA};
    QBrush brush(QColor(100,100,100));
    painter.setBrush(brush);
    painter.drawRect(lewyGorny.x(), lewyGorny.y(), prawyDolny.x(), prawyDolny.y());
}

bool CSciana::czy_mozna_we_mnie_wejsc()
{
    return false;
}
