#include <iostream>
#include <fstream>
using namespace std;

struct lista
{
    int id;
    struct lista *next;
};

//1.Utworz liste
lista* utworz()
{
    lista *L = new lista;
    L->next = NULL;
    return L;
}

//2.W pliku sa dane

//3.Wczytaj dane z pliku na liste
void wczytaj(lista *&L)
{
    ifstream plik("dane.txt");
    int liczba;

    while (plik >> liczba)
    {
        lista *nowy = new lista;
        nowy->id = liczba;
        nowy->next = NULL;

        if (L == NULL)
        {
            L = nowy;
        }
        else
        {
            lista *pom = L;

            while (pom->next != NULL)
                pom = pom->next;

            pom->next = nowy;
        }
    }

    plik.close();
}

//4.Wypisz liste
void wypisz(lista *L)
{
    while (L != NULL)
    {
        cout << L->id << " ";
        L = L->next;
    }
}

//5.Zwolnij pamiec
void zwolnij(lista *&L)
{
    while (L != NULL)
    {
        lista *pom = L;
        L = L->next;
        delete pom;
    }
}

int main()
{
    lista *L = NULL;

    wczytaj(L);
    wypisz(L);
    zwolnij(L);

    return 0;
}
