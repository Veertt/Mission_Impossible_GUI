#include "cgracz.h"
#include "cmapa.h"
#include "Stale.h"

CGracz::CGracz(int x, int y): CObiekt (x,y)
{
}

void CGracz::Wyswietl(QPainter& painter)
{
    SKoordynaty_obiektu koordynaty = Get_koordynaty();
    QPoint p = {koordynaty.K * WIELKOSC_KAFELKA + WIELKOSC_KAFELKA / 2, koordynaty.R * WIELKOSC_KAFELKA + WIELKOSC_KAFELKA / 2};
    QBrush brush(QColor(0,0,255));
    painter.setBrush(brush);
    painter.drawEllipse(p, WIELKOSC_KAFELKA / 2, WIELKOSC_KAFELKA / 2);
}

bool CGracz::czy_mozna_mnie_sledzic()
{
    return true;
}

Rezultat_Ruchu CGracz::Ruch(CMapa *mapa)
{
    SKoordynaty_obiektu poprzednie = Get_koordynaty();
    SKoordynaty_obiektu aktualne = Get_koordynaty();

    for(int i = Get_koordynaty().R-1; i<=Get_koordynaty().R+1; i++)
    {
       for(int j = Get_koordynaty().K-1; j<=Get_koordynaty().K+1; j++)
       {
            CObiekt* pom = mapa->Get_co_jest_na_mapie(i,j);

            if(pom!=NULL&&pom->czy_mozna_za_pomoca_mnie_przegrac())
            {
                return Przegrana;
            }
        }
   }

    if(kbhit())
    {
        sterowanie = getch();

        switch(sterowanie)
        {
            case 119:
                aktualne.R--;
                break;

            case 115:
                aktualne.R++;
                break;

            case 100:
                aktualne.K++;
                break;

            case 97:
                aktualne.K--;
                break;
        }
    }

    CObiekt *pom = mapa->Get_co_jest_na_mapie(aktualne.R,aktualne.K);
    Set_koordynaty(aktualne);

    SKoordynaty_obiektu do_sprawdzenia;
    do_sprawdzenia.R = 0;
    do_sprawdzenia.K = 0;

    if(pom!=NULL)
    {
        for(int i = aktualne.R-1; i<=aktualne.R+1; i++)
        {
           for(int j = aktualne.K-1; j<=aktualne.K+1; j++)
           {
               if(i<mapa->Get_liczba_Wierszy()&&i>=0)
               {
                   do_sprawdzenia.R= i;
               }
               else
               {
                   if(i<0)
                   {
                       do_sprawdzenia.R = 0;
                   }
                   else if(i>=mapa->Get_liczba_Wierszy())
                   {
                       do_sprawdzenia.R = mapa->Get_liczba_Wierszy()-1;
                   }
               }

               if(j<mapa->Get_liczba_Kolumn()&&j>=0)
               {
                   do_sprawdzenia.K = j;
               }
               else
               {
                   if(j<0)
                   {
                       do_sprawdzenia.K = 0;
                   }
                   else if(j>=mapa->Get_liczba_Kolumn())
                   {
                       do_sprawdzenia.K = mapa->Get_liczba_Kolumn()-1;
                   }
               }
                CObiekt* pom = mapa->Get_co_jest_na_mapie(do_sprawdzenia.R,do_sprawdzenia.K);

                if(pom!=NULL&&pom->czy_mozna_za_pomoca_mnie_przegrac())
                {
                    return Przegrana;
                }
            }
        }
        if(pom->czy_za_pomoca_mnie_mozna_wygrac())
        {
            return Wygrana;
        }
        else if(!pom->czy_mozna_we_mnie_wejsc())
        {
            aktualne = poprzednie;
            Set_koordynaty(aktualne);
        }
    }

    return Nic;
}
