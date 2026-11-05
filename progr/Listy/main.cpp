
#include <iostream>
#include <fstream>
using namespace std;

struct lista
{
    int id;
    struct lista *next;
};

//1. Utworz liste
lista* utworz()
{
    lista *L = new lista;
    L->next = NULL;
    return L;
}

//2. Wczytaj dane z pliku na liste
void wczytaj(lista *&L)
{
    ifstream plik("dane.txt");
    int liczba;

    if (!plik)
    {
        cout << "Nie mozna otworzyc pliku" << endl;
        return;
    }

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
    cout << "Wczytano dane z pliku" << endl;
}

//3. Wypisz liste
void wypisz(lista *L)
{
    if (L == NULL)
    {
        cout << "Lista jest pusta" << endl;
        return;
    }

    while (L != NULL)
    {
        cout << L->id << " ";
        L = L->next;
    }

    cout << endl;
}

//4. Zwolnij pamiec
void zwolnij(lista *&L)
{
    while (L != NULL)
    {
        lista *pom = L;
        L = L->next;
        delete pom;
    }
}

//5. Przeszukiwanie listy
bool szukaj(lista *L, int x)
{
    while (L != NULL)
    {
        if (L->id == x)
            return true;

        L = L->next;
    }

    return false;
}

//6. Usuwanie elementu z listy
void usun(lista *&L, int x)
{
    if (L == NULL)
    {
        cout << "Lista jest pusta" << endl;
        return;
    }

    if (L->id == x)
    {
        lista *pom = L;
        L = L->next;
        delete pom;

        cout << "Usunieto element" << endl;
        return;
    }

    lista *pom = L;

    while (pom->next != NULL && pom->next->id != x)
    {
        pom = pom->next;
    }

    if (pom->next != NULL)
    {
        lista *usuniety = pom->next;
        pom->next = usuniety->next;
        delete usuniety;

        cout << "Usunieto element" << endl;
    }
    else
    {
        cout << "Nie znaleziono elementu" << endl;
    }
}

//7. MENU
int main()
{
    lista *L = NULL;
    int wybor, x;

    do
    {
        cout << "====== MENU ======" << endl;
        cout << "1. Wczytaj dane z pliku" << endl;
        cout << "2. Wyswietl liste" << endl;
        cout << "3. Wyszukaj element" << endl;
        cout << "4. Usun element" << endl;
        cout << "5. Zakoncz program" << endl;
        cout << "Wybierz opcje: ";

        cin >> wybor;

        switch (wybor)
        {
            case 1:
                wczytaj(L);
                break;

            case 2:
                cout << "Lista: ";
                wypisz(L);
                break;

            case 3:
                cout << "Podaj liczbe do wyszukania: ";
                cin >> x;

                if (szukaj(L, x))
                    cout << "Znaleziono element" << endl;
                else
                    cout << "Nie znaleziono elementu" << endl;

                break;

            case 4:
                cout << "Podaj liczbe do usuniecia: ";
                cin >> x;

                usun(L, x);
                break;

            case 5:
                cout << "Koniec programu" << endl;
                break;

            default:
                cout << "Nieprawidlowy wybor" << endl;
        }

    } while (wybor != 5);

    zwolnij(L);

    return 0;
}
