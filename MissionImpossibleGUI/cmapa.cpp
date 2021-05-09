#include "cmapa.h"

CMapa::CMapa()
{
}

int CMapa::Get_liczba_Wierszy()
{
    return liczba_Wierszy;
}

int CMapa::Get_liczba_Kolumn()
{
    return liczba_Kolumn;
}

CObiekt ***CMapa::Get_mapa()
{
    return mapa;
}

SWielkosc_mapy CMapa::Sprawdz_jak_duza(string nazwa)
{
    ifstream plik (nazwa.c_str());

    SWielkosc_mapy licznik;
    licznik.ile_Kolumn = 0;
    licznik.ile_Linijek = 0;

    if(plik.good()==true)
    {
        string pom = "";

        while(getline(plik,pom))
        {
            licznik.ile_Linijek++;

            for (int i = 0;i<=pom.size();i++)
            {
                if(pom[i]=='*'&&i>licznik.ile_Kolumn)
                {
                    licznik.ile_Kolumn=i+1;
                }
            }
        }
    }
    plik.close();

    return licznik;
}

CObiekt ***CMapa::Wczytaj_mape(string nazwa, int szybkosc_agenta)
{

    ifstream plik (nazwa.c_str());

    CObiekt* **tablica = new CObiekt* *[liczba_Wierszy];

    for(int i = 0;i<liczba_Wierszy;i++)
    {
        tablica[i]= new CObiekt* [liczba_Kolumn];
    }

    dixtra.Tworzaca_tablice_i_ustawiajaca_jej_poczatkowe_wartosci(liczba_Wierszy,liczba_Kolumn);

    if(plik.good()==true)
    {
        int licznik = 0;

        string pom;

        while(getline(plik,pom))
        {
            for(int i = 0;i<liczba_Kolumn;i++)
            {
                CObiekt* objekt = NULL;
                switch (pom[i])
                {
                    case 'V':
                        objekt = new CAgent(licznik,i,false,szybkosc_agenta);
                        break;
                    case 'H':
                        objekt = new CAgent(licznik,i,true,szybkosc_agenta);
                        break;
                    case 'G':
                        objekt = new CGracz(licznik,i);
                        break;
                    case '*':
                        objekt = new CSciana(licznik,i);
                        dixtra.Nanoszaca_sciany_i_mete_na_tablice(licznik,i);
                        break;
                    case '-':
                        objekt = new CMeta(licznik,i);
                        dixtra.Nanoszaca_sciany_i_mete_na_tablice(licznik,i);
                        break;
                }

                tablica[licznik][i] = objekt;
            }

            licznik++;
        }
    }

    plik.close();

    return tablica;

    plik.close();

    return tablica;
}

CObiekt *CMapa::Get_co_jest_na_mapie(int x, int y)
{
    return mapa[x][y];
}

void CMapa::Set_na_mape(SKoordynaty_obiektu polozenie, CObiekt *obj)
{
    mapa[polozenie.R][polozenie.K] = obj;
}

void CMapa::Wczytaj_w_zaleznosci_do_pozimou_trudnosci(int jaki_poziom)
{
    int szybkosc_agenta = 0;

    if(jaki_poziom == 0)
    {
        szybkosc_agenta = 150;
        SWielkosc_mapy wielkosc = Sprawdz_jak_duza("mapa.txt");
        liczba_Wierszy = wielkosc.ile_Linijek;
        liczba_Kolumn = wielkosc.ile_Kolumn;
        mapa = Wczytaj_mape("mapa.txt",szybkosc_agenta);
    }
    else if (jaki_poziom == 1)
    {
        szybkosc_agenta = 110;
        SWielkosc_mapy wielkosc = Sprawdz_jak_duza("mapa2.txt");
        liczba_Wierszy = wielkosc.ile_Linijek;
        liczba_Kolumn = wielkosc.ile_Kolumn;
        mapa = Wczytaj_mape("mapa2.txt",szybkosc_agenta);
    }
}

void CMapa::Wyswietl(QPainter& painter)
{
    for (int i=0;i<liczba_Wierszy;i++)
    {
        for (int j=0;j<liczba_Kolumn;j++)
        {
            CObiekt *pom = Get_co_jest_na_mapie(i,j);
            if (pom != NULL)
            {
                pom->Wyswietl(painter);
            }
        }
    }
}

SKoordynaty_obiektu CMapa::Znajdz_najkrotsza_do_gracza(SKoordynaty_obiektu agenta, SKoordynaty_obiektu gracza)
{
    dixtra.Ustawiajaca_tablice();

    Sprawdzajaca_gdzie_sa_pozostali_agenci(agenta);

    dixtra.Oblicz(agenta);

    SKoordynaty_obiektu aktualne = gracza;
    SKoordynaty_obiektu poprzednika;
    poprzednika = dixtra.Get_tablica_poprzednik(aktualne);

    while(!(poprzednika.R==agenta.R&&poprzednika.K==agenta.K))
    {
        aktualne = poprzednika;
        poprzednika = dixtra.Get_tablica_poprzednik(aktualne);
    }

    return aktualne;
}

void CMapa::Sprawdzajaca_gdzie_sa_pozostali_agenci(SKoordynaty_obiektu obecnego)
{
    for (int i=0;i<liczba_Wierszy;i++)
    {
        for (int j=0;j<liczba_Kolumn;j++)
        {
            CObiekt *pom = Get_co_jest_na_mapie(i,j);
            if (pom !=NULL && pom->czy_mozna_za_pomoca_mnie_przegrac() && obecnego.R!=i && obecnego.K!=j)
            {
                dixtra.Nanoszaca_pozostalych_agentow(i,j);
            }
        }
    }
}

CMapa::~CMapa()
{
    for(int i = 0; i<liczba_Wierszy; i++)
    {
        for (int j=0;j<liczba_Kolumn; j++)
        {
            delete mapa[i][j];
        }
        delete [] mapa [i];
    }

    delete [] mapa;
}
