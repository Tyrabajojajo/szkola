#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Rekord osoby
struct Osoba
{
    string imie;
    string nazwisko;
    int nrWDzienniku;
};

// Klasa przechowuj¹ca osoby
class Klasa
{
private:
    Osoba osoby[30];
    int liczbaOsob;

public:
    Klasa()
    {
        liczbaOsob = 0;
    }

    // Wczytywanie danych z pliku
    void wczytajZPliku(string nazwaPliku)
    {
        ifstream plik(nazwaPliku);

        if (!plik)
        {
            cout<<"Nie mozna otworzyc pliku"<<endl;
            return;
        }

        liczbaOsob = 0;

        while (liczbaOsob < 30 &&
               plik >>osoby[liczbaOsob].imie
                    >>osoby[liczbaOsob].nazwisko
                    >>osoby[liczbaOsob].nrWDzienniku)
        {
            liczbaOsob++;
        }

        plik.close();
    }

    // Sortowanie wed³ug nazwiska
    void sortujPoNazwisku()
    {
        sort(osoby, osoby + liczbaOsob, [](const Osoba& a, const Osoba& b)
            {
                return a.nazwisko < b.nazwisko;
            });
    }

    // Zwraca liczbê uczniów
    int ileUczniow()
    {
        return liczbaOsob;
    }

    // Zapisywanie wyniku do pliku
    void zapiszDoPliku(string nazwaPliku)
    {
        ofstream plik(nazwaPliku);

        if (!plik)
        {
            cout<<"Nie mozna utworzyc pliku"<<endl;
            return;
        }

        for (int i = 0; i < liczbaOsob; i++)
        {
            plik <<osoby[i].imie<<" "
                 <<osoby[i].nazwisko<<" "
                 <<osoby[i].nrWDzienniku<<endl;
        }

        plik.close();
    }
};

int main()
{
    Klasa klasa;

    klasa.wczytajZPliku("osoby.txt");

    cout<<"Liczba uczniow: "<<klasa.ileUczniow()<<endl;

    klasa.sortujPoNazwisku();

    klasa.zapiszDoPliku("wynik.txt");

    cout<<"Dane zostaly posortowane i zapisane do pliku"<<endl;

    return 0;
}
