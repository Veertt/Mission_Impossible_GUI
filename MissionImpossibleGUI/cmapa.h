#ifndef CMAPA_H
#define CMAPA_H
#include <fstream>
#include <iostream> //niepotrzebne
#include "cobiekt.h"
#include "cgracz.h"
#include "cagent.h"
#include "csciana.h"
#include "cmeta.h"
#include "cdixtra.h"
#include <QPainter>

using namespace std;

struct SWielkosc_mapy
{
    int ile_Linijek;
    int ile_Kolumn;
};

class CMapa
{
private:
    int liczba_Wierszy;
    int liczba_Kolumn;
    CObiekt ***mapa;

    SWielkosc_mapy Sprawdz_jak_duza(string nazwa);
    CObiekt ***Wczytaj_mape(string nazwa, int szybkosc_agenta);

    CDixtra dixtra;

public:
    CMapa();

    CObiekt  ***Get_mapa();

    int Get_liczba_Wierszy();
    int Get_liczba_Kolumn();

    CObiekt *Get_co_jest_na_mapie(int x, int y);
    void Set_na_mape(SKoordynaty_obiektu polozenie, CObiekt *obj);

    void Wczytaj_w_zaleznosci_do_pozimou_trudnosci(int jaki_poziom);

    void Wyswietl(QPainter& painter);

    SKoordynaty_obiektu Znajdz_najkrotsza_do_gracza(SKoordynaty_obiektu agenta, SKoordynaty_obiektu gracza);
    void Sprawdzajaca_gdzie_sa_pozostali_agenci(SKoordynaty_obiektu obecnego);

    ~CMapa();
};

#endif // CMAPA_H
