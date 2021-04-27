#include "cgra.h"
#include <QPainter>

CGra::CGra()
{
   // cout<<"Opracowal: Bartlomiej Gus gr.IPAUT-161 nr albumu: 297415"<<endl;
   // cout<<"Witaj w MissionImpossible!"<<endl;

    //bool czy_gramy  = Wstep();
    poziom_trudnosci = 0;

    //if(czy_gramy == true)
    {
        map.Wczytaj_w_zaleznosci_do_pozimou_trudnosci(poziom_trudnosci);
        koniec.czy_wygrales = false;
        koniec.czy_przegrales = false;

//        do
//        {

//        }
//        while(koniec.czy_wygrales == false&&koniec.czy_przegrales == false);

//        if(koniec.czy_wygrales == true)
//        {
//            Wyswietl_aktualna();
//            cout<<"Brawo, wygrales!";
//        }
//        else if(koniec.czy_przegrales == true)
//        {
//            Wyswietl_aktualna();
//            cout<<"Niestety przegrales.";
//        }
    }

    //cout<<endl;
    //exit(0);
}

CGra::SCzy_koniec CGra::Kolejna_klatka()
{
    Ruch_obiektow();
    Ustawienie_obiektow();
    return koniec;
}

bool CGra::Wstep()
{
    poziom_trudnosci = 0;
    return true;

    int  wybor_uzytkownika;
    bool czy_gramy_czy_nie = true;

    do
    {
        cout<<endl;
        gotoxy(0,2);
        cout<<"Nacisniecie przycisku t spowoduje wlaczenie gry."<<endl;
        cout<<"Nacisniecie przycisku z spowoduje pokazanie zasad gry."<<endl;
        cout<<"Nacisniecie przycisku ESC spowoduje wyjscie z gry."<<endl;

        wybor_uzytkownika = getch();

    }while(!(wybor_uzytkownika==116||wybor_uzytkownika==122||wybor_uzytkownika==27));

    if(wybor_uzytkownika==122)
    {
        Przedstawienie_zasad_gry(wybor_uzytkownika);
    }

    if(wybor_uzytkownika==27)
    {
        system("cls");
        cout<<"Wyszedles z gry, do zobaczenia!";
        czy_gramy_czy_nie = false;
        return czy_gramy_czy_nie;
    }

    do
    {
        system("cls");
        cout<<"Opracowal: Bartlomiej Gus gr.IPAUT-161 nr albumu: 297415"<<endl<<endl;
        cout<<"Nacisniecie przycisku 0 spowoduje latwy tryb gry."<<endl;
        cout<<"Nacisniecie przycisku 1 spowoduje trudny tryb gry."<<endl;

        wybor_uzytkownika = getch();

    }while(!(wybor_uzytkownika==48||wybor_uzytkownika==49));

    if(wybor_uzytkownika==48)
    {
        poziom_trudnosci = 0;
    }
    else if(wybor_uzytkownika==49)
    {
        poziom_trudnosci = 1;
    }

    return czy_gramy_czy_nie;
}

void CGra::Przedstawienie_zasad_gry(int &wybor)
{
    do
    {
        system("cls");
        ifstream plik ("zasady_gry.txt");

        if(plik.good()==true)
        {
            string pom = "";

            while(getline(plik,pom))
            {
                cout<<pom<<endl;
            }
        }

        cout<<endl;

        cout<<"Nacisniecie przycisku t spowoduje wlaczenie gry."<<endl;
        cout<<"Nacisniecie przycisku ESC spowoduje wyjscie z gry."<<endl;

        wybor = getch();

        plik.close();

    }while(!(wybor==116||wybor==27));

}

void CGra::Wyswietl_aktualna(QPainter& painter)
{
    map.Wyswietl(painter);
}

void CGra::Ruch_obiektow()
{
    for(int i = 0;i<map.Get_liczba_Wierszy();i++)
    {
        for(int j = 0;j<map.Get_liczba_Kolumn();j++)
        {
            CObiekt *pom = map.Get_co_jest_na_mapie(i,j);

            if(pom!=NULL)
            {
                Rezultat_Ruchu rezultat_aktualny = pom->Ruch(&map);

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

//void gotoxy( int x, int y )
//{
//    COORD c;
//    c.X = x;
//    c.Y = y;
//    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), c );
//}
