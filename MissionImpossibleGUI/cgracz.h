#ifndef CGRACZ_H
#define CGRACZ_H

#include "cobiekt.h"

class CGracz : public CObiekt
{
private:
    int sterowanie;

public:
    CGracz(int x, int y);

    virtual Rezultat_Ruchu Ruch_dla_gracza(CMapa* mapa, int sterowanie);
    virtual void Wyswietl(QPainter& painter);
    virtual bool czy_mozna_mnie_sledzic();
    virtual bool czy_mozna_we_mnie_wejsc();
};

#endif // CGRACZ_H
