#include <iostream>
#include <fstream>
using namespace std;

// Struktura pojedynczego elementu drzewa
struct drzewo
{
    int liczba;
    struct drzewo *lewy, *prawy;
};

// Zmienna globalna zliczająca usunięte elementy
int usuniete = 0;

// Funkcja dodająca liczbę do drzewa
void wstaw(struct drzewo *&d, int liczba)
{
    // Jeżeli miejsce jest puste, tworzymy nowy element
    if (d == NULL)
    {
        d = new struct drzewo;
        d->liczba = liczba;
        d->lewy = NULL;
        d->prawy = NULL;
        return;
    }

    // Jeżeli liczba jest większa, przechodzimy do prawego poddrzewa
    if (liczba > d->liczba)
        wstaw(d->prawy, liczba);
    // W przeciwnym przypadku przechodzimy do lewego poddrzewa
    else
        wstaw(d->lewy, liczba);
}

// Funkcja rekurencyjnie wypisująca drzewo rosnąco
void wypisz(struct drzewo *d)
{
    // Jeżeli drzewo jest puste, kończymy funkcję
    if (d == NULL)
        return;

    // Najpierw wypisujemy lewe poddrzewo
    wypisz(d->lewy);

    // Następnie wypisujemy wartość z korzenia
    cout << d->liczba << " ";

    // Na końcu wypisujemy prawe poddrzewo
    wypisz(d->prawy);
}

// Funkcja usuwająca całe drzewo z pamięci
void usun(struct drzewo *d)
{
    // Jeżeli element nie istnieje, kończymy funkcję
    if (d == NULL)
        return;

    // Najpierw usuwamy lewe poddrzewo
    usun(d->lewy);

    // Następnie usuwamy prawe poddrzewo
    usun(d->prawy);

    // Usuwamy aktualny element drzewa
    delete d;

    // Zwiększamy licznik usuniętych elementów
    usuniete++;
}

int main()
{
    // Tworzymy puste drzewo
    struct drzewo *d = NULL;

    // Otwieramy plik z liczbami
    ifstream plik("liczby.txt");

    // Sprawdzamy, czy plik został poprawnie otwarty
    if (!plik)
    {
        cout << "Nie mozna otworzyc pliku!";
        return 1;
    }

    int liczba;
    int wczytane = 0;

    // Wczytujemy liczby z pliku po jednej
    while (plik >> liczba)
    {
        // Dodajemy każdą liczbę do drzewa
        wstaw(d, liczba);

        // Zwiększamy licznik wczytanych liczb
        wczytane++;
    }

    // Zamykamy plik
    plik.close();

    // Wypisujemy liczby w kolejności rosnącej
    cout << "Liczby posortowane rosnaco: ";
    wypisz(d);

    cout << endl;

    // Usuwamy całe drzewo z pamięci
    usun(d);

    // Zerujemy wskaźnik po usunięciu drzewa
    d = NULL;

    // Wyświetlamy liczbę wczytanych i usuniętych elementów
    cout << "Liczba rekordow wczytanych: " << wczytane << endl;
    cout << "Usunieto rekordow z pamieci: " << usuniete << endl;

    // Sprawdzamy, czy wszystkie elementy zostały usunięte
    if (wczytane == usuniete)
        cout << "Wszystkie rekordy zostaly usuniete!";
    else
        cout << "Liczba usunietych rekordow sie nie zgadza!";

    return 0;
}
