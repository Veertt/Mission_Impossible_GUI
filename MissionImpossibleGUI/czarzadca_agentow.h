#ifndef CZARZADCA_AGENTOW_H
#define CZARZADCA_AGENTOW_H

#include "SKoordynaty.h"

struct SLista_Agentow
{
    bool czy_wiem_gdzie_jest_gracz;
    int ktorym_agentem_jestem;
    SLista_Agentow *next;
};

class CMapa;

class CZarzadca_Agentow
{
private:
    SLista_Agentow *head;

public:
    CZarzadca_Agentow();
    static int ile_agentow;
    static bool czy_wiemy_gdzie_jest_gracz;
    static SKoordynaty_obiektu wspolrzedne_gracza;

    void Dodaj_kolejnego_agenta(int ktory);
    void Dodaj_ze_zobaczylem_gracza(int ktory);
    void Zmien_ze_nie_widze_gracza(int ktory);

    void Aktualizujaca_czy_na_pewno_nadal_widze_gracza();

    void Sprawdzajaca_czy_wiemy_gdzie_jest_gracz(CMapa *mapa, int wielkosc_obszaru, SKoordynaty_obiektu aktualne, bool orientacja, bool w_ktora_strone, int ktory);
    void Ustawiajaca_do_kazdego_agenta_widocznosc(int &kl, int &kp, int &rg, int &rd, bool orientacja, bool w_ktora_strone);

    ~CZarzadca_Agentow();
};

#endif // CZARZADCA_AGENTOW_H


//orientacja = false - oznacza, że agent ma się poruszać pionowo
//orientacja = true - oznacza, że agent ma się poruszać poziomo
// jeśli w_ktora_strone jest true to odejmuje do współrzednej
// jeśli w_ktora_strone jest false to dodaje od współrzędnej
