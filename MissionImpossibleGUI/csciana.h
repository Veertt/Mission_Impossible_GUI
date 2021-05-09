#ifndef CSCIANA_H
#define CSCIANA_H

#include "cobiekt.h"

class CSciana : public CObiekt
{
public:
    CSciana(int x, int y);
    virtual Rezultat_Ruchu Ruch(CMapa* mapa);
    virtual void Wyswietl(QPainter& painter);
    virtual bool czy_mozna_we_mnie_wejsc();
};


#endif // CSCIANA_H
