#ifndef CGRACZ_H
#define CGRACZ_H
#include "cobiekt.h"
#include "conio.h"

class CGracz : public CObiekt
{
private:
    int sterowanie;
public:
    CGracz(int x, int y);

    virtual Rezultat_Ruchu Ruch(CMapa* mapa);
    virtual void Wyswietl(QPainter& painter);
    virtual bool czy_mozna_mnie_sledzic();
};

#endif // CGRACZ_H
