Program do zarządzania listą uczniów
Opis

Program napisany w języku C++, którego zadaniem jest wczytanie danych uczniów z pliku, zapisanie ich w tablicy, posortowanie alfabetycznie według nazwiska oraz zapisanie posortowanej listy do nowego pliku.

Program wykorzystuje:

struct do przechowywania danych pojedynczej osoby,

class do zarządzania listą uczniów,

tablicę o maksymalnym rozmiarze 30 osób,

obsługę plików tekstowych,

sortowanie alfabetyczne za pomocą std::sort.

Struktura danych

Pojedynczy uczeń jest reprezentowany przez strukturę Osoba, która zawiera:

struct Osoba
{
    string imie;
    string nazwisko;
    int nrWDzienniku;
};


Każda osoba posiada:

imię,

nazwisko,

numer w dzienniku.

Klasa Klasa

Klasa przechowuje maksymalnie 30 uczniów:

Osoba osoby[30];


Zawiera również zmienną liczbaOsob, która przechowuje aktualną liczbę wczytanych uczniów.

Główne funkcje
wczytajZPliku()

Wczytuje dane uczniów z podanego pliku tekstowego. Program odczytuje imię, nazwisko oraz numer w dzienniku.

sortujPoNazwisku()

Sortuje uczniów alfabetycznie według nazwiska za pomocą funkcji std::sort.

ileUczniow()

Zwraca aktualną liczbę uczniów znajdujących się w tablicy.

zapiszDoPliku()

Zapisuje posortowaną listę uczniów do podanego pliku tekstowego.

Format pliku wejściowego

Dane powinny znajdować się w pliku osoby.txt.

Każdy uczeń powinien być zapisany w osobnej linii:

Jan Kowalski 5
Anna Nowak 2
Piotr Adamski 1
Maria Zielinska 4
Tomasz Wozniak 3


Format:

imie nazwisko numer_w_dzienniku

Plik wynikowy

Po wykonaniu programu posortowane dane zostają zapisane do pliku wynik.txt.

Przykładowy wynik:

Piotr Adamski 1
Jan Kowalski 5
Jan Kowalski 5
Tomasz Wozniak 3
Maria Zielinska 4

Przebieg działania

Program tworzy obiekt klasy Klasa.

Wczytuje dane z pliku osoby.txt.

Wyświetla liczbę wczytanych uczniów.

Sortuje uczniów alfabetycznie według nazwiska.

Zapisuje posortowane dane do wynik.txt.

Ograniczenia

Program może przechowywać maksymalnie 30 uczniów.

Imię i nazwisko nie powinny zawierać spacji.

Plik wejściowy musi mieć odpowiedni format.

Jeśli plik nie istnieje lub nie można go otworzyć, program wyświetli komunikat o błędzie.