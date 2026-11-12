#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;

struct lista2
{
    int liczba;
    lista2* next;
    lista2* prev;
};

// INSERTION SORT - TABLICA
void insertionSortTab(int tab[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int klucz = tab[i];
        int j = i - 1;

        while (j >= 0 && tab[j] > klucz)
        {
            tab[j + 1] = tab[j];
            j--;
        }

        tab[j + 1] = klucz;
    }
}

// INSERTION SORT - LISTA DWUKIERUNKOWA
void insertionSortLista(lista2* head)
{
    if (head == nullptr)
        return;

    lista2* aktualny = head->next;

    while (aktualny != nullptr)
    {
        int klucz = aktualny->liczba;
        lista2* poprzedni = aktualny->prev;

        while (poprzedni != nullptr &&
               poprzedni->liczba > klucz)
        {
            poprzedni->next->liczba = poprzedni->liczba;
            poprzedni = poprzedni->prev;
        }

        if (poprzedni == nullptr)
            head->liczba = klucz;
        else
            poprzedni->next->liczba = klucz;

        aktualny = aktualny->next;
    }
}

int main()
{
    const int N = 10000;

    int* tab = new int[N];

    lista2* head = nullptr;
    lista2* tail = nullptr;

    srand(time(NULL));

    // Generowanie danych
    for (int i = 0; i < N; i++)
    {
        int x = rand() % 100000;

        tab[i] = x;

        lista2* nowy = new lista2;
        nowy->liczba = x;
        nowy->next = nullptr;
        nowy->prev = tail;

        if (head == nullptr)
            head = nowy;
        else
            tail->next = nowy;

        tail = nowy;
    }

    // SORTOWANIE TABLICY
    auto start1 = chrono::high_resolution_clock::now();

    insertionSortTab(tab, N);

    auto stop1 = chrono::high_resolution_clock::now();

    // SORTOWANIE LISTY
    auto start2 = chrono::high_resolution_clock::now();

    insertionSortLista(head);

    auto stop2 = chrono::high_resolution_clock::now();

    // POMIAR CZASU
    auto czasTab = chrono::duration<double, milli>
        (stop1 - start1).count();

    auto czasLista = chrono::duration<double, milli>
        (stop2 - start2).count();

    cout << "Sortowanie tablicy: "
         << czasTab << " ms" << endl;

    cout << "Sortowanie listy: "
         << czasLista << " ms" << endl;

    if (czasTab < czasLista)
        cout << "Szybsza jest tablica!" << endl;
    else if (czasLista < czasTab)
        cout << "Szybsza jest lista!" << endl;
    else
        cout << "Czasy sa takie same!" << endl;

    // Usuwanie pamieci
    delete[] tab;

    while (head != nullptr)
    {
        lista2* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
