#ifndef CAGENT_H
#define CAGENT_H
#include "cobiekt.h"
#include "czarzadca_agentow.h"
#include <chrono>

using namespace std::chrono;

class CAgent : public CObiekt
{
private:
    system_clock::duration krok;
    system_clock::time_point czas;

    bool orientacja;
    bool w_ktora_strone;
    int ktory_agent;
    int wielkosc_obszaru_poszukiwan;

public:
    CAgent(int x, int y, bool orientation, int krok_agenta);

    virtual Rezultat_Ruchu Ruch(CMapa *mapa,int sterowanie);
    virtual void Wyswietl(QPainter& painter);
    virtual bool czy_mozna_za_pomoca_mnie_przegrac();
    virtual bool czy_mozna_we_mnie_wejsc();

    static CZarzadca_Agentow zarzadca;

    SKoordynaty_obiektu do_Ruchu_dla_pionowych(CMapa* mapa);
    SKoordynaty_obiektu do_Ruchu_dla_poziomych(CMapa* mapa);
};

#endif // CAGENT_H


//orientacja = false - oznacza, że agent ma się poruszać pionowo
//orientacja = true - oznacza, że agent ma się poruszać poziomo
// jeśli w_ktora_strone jest true to odejmuje do współrzednej
// jeśli w_ktora_strone jest false to dodaje od współrzędnej
