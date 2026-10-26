#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <cctype>

#include "Pojazd.h"
#include "Samochod.h"
#include "Motocykl.h"

using namespace std;

vector<string> podzielLinie(const string& linia) {
    vector<string> pola;
    string pole;
    stringstream ss(linia);

    while (getline(ss, pole, ';')) {
        pola.push_back(pole);
    }

    return pola;
}

string trim(const string& tekst) {
    size_t poczatek = tekst.find_first_not_of(" \t\r\n");

    if (poczatek == string::npos)
        return "";

    size_t koniec = tekst.find_last_not_of(" \t\r\n");
    return tekst.substr(poczatek, koniec - poczatek + 1);
}

bool odczytajBool(const string& tekst) {
    string wartosc = trim(tekst);

    transform(wartosc.begin(), wartosc.end(),
              wartosc.begin(),
              [](unsigned char c) {
                  return static_cast<char>(tolower(c));
              });

    if (wartosc == "true" || wartosc == "1")
        return true;

    if (wartosc == "false" || wartosc == "0")
        return false;

    throw invalid_argument(
        "Nieprawidlowa wartosc skrzyni biegow. Uzyj true lub false."
    );
}

int main() {
    setlocale(LC_ALL, "");

    ifstream plik("pojazdy.txt");

    if (!plik.is_open()) {
        cerr << "Blad: nie mozna otworzyc pliku pojazdy.txt\n";
        cerr << "Umiesc plik w katalogu roboczym programu.\n";
        return 1;
    }

    vector<unique_ptr<Pojazd>> pojazdy;
    string linia;
    int numerLinii = 0;

    while (getline(plik, linia)) {
        ++numerLinii;
        linia = trim(linia);

        if (linia.empty())
            continue;

        vector<string> pola = podzielLinie(linia);

        try {
            if (pola.empty())
                continue;

            string typ = trim(pola[0]);

            if (typ == "SAMOCHOD") {
                if (pola.size() != 6)
                    throw invalid_argument(
                        "Samochod wymaga 6 pol oddzielonych srednikami."
                    );

                pojazdy.push_back(make_unique<Samochod>(
                    trim(pola[1]),
                    trim(pola[2]),
                    stoi(trim(pola[3])),
                    stoi(trim(pola[4])),
                    odczytajBool(pola[5])
                ));
            }
            else if (typ == "MOTOCYKL") {
                if (pola.size() != 6)
                    throw invalid_argument(
                        "Motocykl wymaga 6 pol oddzielonych srednikami."
                    );

                pojazdy.push_back(make_unique<Motocykl>(
                    trim(pola[1]),
                    trim(pola[2]),
                    stoi(trim(pola[3])),
                    trim(pola[4]),
                    stoi(trim(pola[5]))
                ));
            }
            else {
                throw invalid_argument(
                    "Nieznany typ pojazdu: " + typ
                );
            }
        }
        catch (const exception& e) {
            cerr << "Blad w linii " << numerLinii
                 << ": " << e.what() << '\n';
        }
    }

    plik.close();

    cout << "===== LISTA POJAZDOW =====\n\n";

    if (pojazdy.empty()) {
        cout << "Brak poprawnych danych do wyswietlenia.\n";
    }

    for (const auto& pojazd : pojazdy) {
        cout << *pojazd << '\n';
        cout << "--------------------------\n";
    }

    cout << "Liczba wczytanych pojazdow: "
         << pojazdy.size() << '\n';

    return 0;
}
