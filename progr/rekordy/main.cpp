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

// Klasa przechowujaca osoby
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
            cout << "Nie mozna otworzyc pliku." << endl;
            return;
        }

        liczbaOsob = 0;

        while (liczbaOsob < 30 &&
               plik >> osoby[liczbaOsob].imie
                    >> osoby[liczbaOsob].nazwisko
                    >> osoby[liczbaOsob].nrWDzienniku)
        {
            liczbaOsob++;
        }

        plik.close();

        cout << "Dane zostaly wczytane" << endl;
    }

    // Wypisywanie osob
    void wypisz()
    {
        if (liczbaOsob == 0)
        {
            cout << "Brak osob w klasie." << endl;
            return;
        }

        cout << "\nLista osob:\n";

        for (int i = 0; i < liczbaOsob; i++)
        {
            cout << i + 1 << ". "
                 << osoby[i].imie << " "
                 << osoby[i].nazwisko
                 << " - nr w dzienniku: "
                 << osoby[i].nrWDzienniku
                 << endl;
        }
    }

    // Dodawanie osoby
    void dodaj()
    {
        if (liczbaOsob >= 30)
        {
            cout << "Nie mozna dodac osoby" << endl;
            return;
        }

        cout << "Podaj imie: ";
        cin >> osoby[liczbaOsob].imie;

        cout << "Podaj nazwisko: ";
        cin >> osoby[liczbaOsob].nazwisko;

        cout << "Podaj numer w dzienniku: ";
        cin >> osoby[liczbaOsob].nrWDzienniku;

        liczbaOsob++;

        // Zapisanie aktualnej listy do pliku
        zapiszDoPliku("osoby.txt");

        cout << "Osoba zostala dodana" << endl;
    }

    // Sortowanie wedlug nazwiska
    void sortujPoNazwisku()
    {
        sort(osoby, osoby + liczbaOsob,
             [](const Osoba& a, const Osoba& b)
             {
                 return a.nazwisko < b.nazwisko;
             });

        cout << "Osoby zostaly posortowane po nazwisku" << endl;
    }

    // Usuwanie osoby po numerze w dzienniku
    void usun()
    {
        int numer;

        cout << "Podaj numer w dzienniku osoby do usuniecia: ";
        cin >> numer;

        int indeks = -1;

        for (int i = 0; i < liczbaOsob; i++)
        {
            if (osoby[i].nrWDzienniku == numer)
            {
                indeks = i;
                break;
            }
        }

        if (indeks == -1)
        {
            cout << "Nie znaleziono osoby o takim numerze" << endl;
            return;
        }

        // Przesuwanie kolejnych osob o jedno miejsce w lewo
        for (int i = indeks; i < liczbaOsob - 1; i++)
        {
            osoby[i] = osoby[i + 1];
        }

        liczbaOsob--;

        cout << "Osoba zostala usunieta" << endl;
    }

    // Zwraca liczbe uczniow
    int ileUczniow()
    {
        return liczbaOsob;
    }

    // Zapisywanie do pliku
    void zapiszDoPliku(string nazwaPliku)
    {
        ofstream plik(nazwaPliku);

        if (!plik)
        {
            cout << "Nie mozna utworzyc pliku" << endl;
            return;
        }

        for (int i = 0; i < liczbaOsob; i++)
        {
            plik << osoby[i].imie << " "
                 << osoby[i].nazwisko << " "
                 << osoby[i].nrWDzienniku << endl;
        }

        plik.close();

        cout << "Dane zostaly zapisane do pliku" << endl;
    }
};

int main()
{
    Klasa klasa;

    int wybor;

    do
    {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Wczytaj z pliku" << endl;
        cout << "2. Wypisz osoby" << endl;
        cout << "3. Zapisz do pliku" << endl;
        cout << "4. Dodaj osobe" << endl;
        cout << "5. Posortuj po nazwisku" << endl;
        cout << "6. Usun osobe po numerze w dzienniku" << endl;
        cout << "7. Pokaz liczbe uczniow" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor)
        {
            // Wczytanie osob z pliku osoby.txt
            case 1:
                klasa.wczytajZPliku("osoby.txt");
                break;

            // Wyswietlenie osob na ekranie
            case 2:
                klasa.wypisz();
                break;

            // Zapisanie danych do pliku wynik.txt
            case 3:
                klasa.zapiszDoPliku("wynik.txt");
                break;

            // Dodanie nowej osoby
            case 4:
                klasa.dodaj();
                break;

            // Sortowanie osob po nazwisku
            case 5:
                klasa.sortujPoNazwisku();
                break;

            // Usuniecie osoby po numerze w dzienniku
            case 6:
                klasa.usun();
                break;

            // Wyswietlenie liczby osob
            case 7:
                cout << "Liczba uczniow: "
                     << klasa.ileUczniow()
                     << endl;
                break;

            // Zakonczenie programu
            case 0:
                cout << "Koniec programu." << endl;
                break;

            // Obsluga nieprawidlowej opcji
            default:
                cout << "Nieprawidlowa opcja." << endl;
        }

    } while (wybor != 0);

    return 0;
}
