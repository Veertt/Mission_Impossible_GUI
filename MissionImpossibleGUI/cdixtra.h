#ifndef CDIXTRA_H
#define CDIXTRA_H
#include "cobiekt.h"

struct Do_Dixtra
{
    int koszty;
    bool czy_juz_byl;
    SKoordynaty_obiektu poprzednik;
};

class CDixtra
{
private:
    int liczba_Wierszy_Mapy;
    int liczba_Kolumn_Mapy;
    Do_Dixtra **tablica;

public:
    CDixtra();

    void Tworzaca_tablice_i_ustawiajaca_jej_poczatkowe_wartosci(int liczba_Wierszy_M, int liczba_Kolumn_M);
    void Nanoszaca_sciany_i_mete_na_tablice(int rzad, int kolumna);
    void Nanoszaca_pozostalych_agentow(int rzad, int kolumna);

    void Oblicz(SKoordynaty_obiektu agenta);
    SKoordynaty_obiektu Znajdz_najmniejszy();
    void Ustawiajaca_tablice();

    SKoordynaty_obiektu Get_tablica_poprzednik(SKoordynaty_obiektu obecne);
    void Wyswietl_tablice();//niepotrzebne

    ~CDixtra();

};

#endif // CDIXTRA_H
