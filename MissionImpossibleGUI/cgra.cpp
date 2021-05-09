#include "cgra.h"
#include <QPainter>
#include <QDebug>

CGra::CGra()
{
    koniec.czy_wygrales = false;
    koniec.czy_przegrales = false;
}

int CGra::Get_poziom_trudnosci()
{
    return poziom_trudnosci;
}

int CGra::Get_liczba_wierszy()
{
    return map.Get_liczba_Wierszy();
}

int CGra::Get_liczba_kolumn()
{
    return map.Get_liczba_Kolumn();
}

void CGra::Wczytaj_w_zaleznosci_od_poziomu(int level)
{
    poziom_trudnosci = level;

    map.Wczytaj_w_zaleznosci_do_pozimou_trudnosci(poziom_trudnosci);
    koniec.czy_wygrales = false;
    koniec.czy_przegrales = false;
}

CGra::SCzy_koniec CGra::Kolejna_klatka(int &control)
{
    Ruch_obiektow(control);
    Ustawienie_obiektow();
    return koniec;
}

void CGra::Wyswietl_aktualna(QPainter &painter)
{
    map.Wyswietl(painter);
}

void CGra::Ruch_obiektow(int &sterowanie)
{
    for(int i = 0;i<map.Get_liczba_Wierszy();i++)
    {
        for(int j = 0;j<map.Get_liczba_Kolumn();j++)
        {
            CObiekt *pom = map.Get_co_jest_na_mapie(i,j);

            if(pom!=NULL)
            {
                Rezultat_Ruchu rezultat_aktualny;

                if(pom->czy_mozna_mnie_sledzic())
                {
                    rezultat_aktualny = pom->Ruch_dla_gracza(&map,sterowanie);
                }
                else
                {
                    rezultat_aktualny = pom->Ruch(&map);
                }

                if(rezultat_aktualny==Przegrana)
                {
                    koniec.czy_przegrales = true;
                    return;
                }
                else if(rezultat_aktualny==Wygrana)
                {
                    koniec.czy_wygrales = true;
                    return;
                }
            }
        }
    }
}

void CGra::Ustawienie_obiektow()
{
    for(int i = 0;i<map.Get_liczba_Wierszy();i++)
    {
        for(int j = 0;j<map.Get_liczba_Kolumn();j++)
        {
            CObiekt *pom = map.Get_co_jest_na_mapie(i,j);

            if(pom!=NULL)
            {
                SKoordynaty_obiektu koordynaty_obiektu_na_mapie;
                koordynaty_obiektu_na_mapie.R = i;
                koordynaty_obiektu_na_mapie.K = j;

                SKoordynaty_obiektu koordynaty_obiektu_w_obiekcie = pom->Get_koordynaty();
                CObiekt* pom2 = map.Get_co_jest_na_mapie(koordynaty_obiektu_w_obiekcie.R, koordynaty_obiektu_w_obiekcie.K);
                if((pom2 == NULL || pom2->czy_mozna_we_mnie_wejsc()) && (koordynaty_obiektu_w_obiekcie.R!=i||koordynaty_obiektu_w_obiekcie.K!=j))
                {
                    map.Set_na_mape(koordynaty_obiektu_w_obiekcie,pom);
                    map.Set_na_mape(koordynaty_obiektu_na_mapie,NULL);
                }
                else
                {
                    pom->Set_koordynaty(koordynaty_obiektu_na_mapie);
                }
            }
        }
    }
}
