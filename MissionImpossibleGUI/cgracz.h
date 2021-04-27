#ifndef CGRACZ_H
#define CGRACZ_H
#include "cobiekt.h"
#include "conio.h"
#include "QWidget"
#include "QKeyEvent"

class CGracz : public CObiekt, public QWidget
{
private:
    int sterowanie;
    void keyPressEvent(QKeyEvent *event);

public:
    CGracz(int x, int y);

    virtual Rezultat_Ruchu Ruch(CMapa* mapa);
    virtual void Wyswietl(QPainter& painter);
    virtual bool czy_mozna_mnie_sledzic();
    virtual bool czy_mozna_we_mnie_wejsc();
};

#endif // CGRACZ_H
