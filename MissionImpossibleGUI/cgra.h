#ifndef CGRA_H
#define CGRA_H

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

    void Ruch_obiektow(int &sterowanie);
    void Ustawienie_obiektow();

public:
    CGra();
    SCzy_koniec Kolejna_klatka(int &control);
    void Wyswietl_aktualna(QPainter &painter);
    void Wczytaj_w_zaleznosci_od_poziomu(int level);

    int Get_poziom_trudnosci();
    int Get_liczba_wierszy();
    int Get_liczba_kolumn();
};

#endif // CGRA_H

