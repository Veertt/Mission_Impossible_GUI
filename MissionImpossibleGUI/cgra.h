#ifndef CGRA_H
#define CGRA_H
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include "cmapa.h"
#include "cobiekt.h"
#include <QWidget>

class CGra
{
public:
    struct SCzy_koniec
    {
        bool czy_wygrales;
        bool czy_przegrales;
    };

private:
    SCzy_koniec koniec;
    int poziom_trudnosci;
    CMapa map;

    bool Wstep();
    void Przedstawienie_zasad_gry(int &wybor);

    void Ruch_obiektow();
    void Ustawienie_obiektow();

public:
    CGra();
    SCzy_koniec Kolejna_klatka();
    void Wyswietl_aktualna(QPainter& painter);
};

//funkcja służaca do odświeżania
void gotoxy( int x, int y );

#endif // CGRA_H

