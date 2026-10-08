#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

int main() {
    const int N = 100000;
    const int K = 50000;

    vector<int> liczby(N);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> losuj(1, 1000000);

    for (int i = 0; i < N; i++)
        liczby[i] = losuj(gen);

    // VECTOR
    {
        vector<int> v;

        auto start = high_resolution_clock::now();

        for (int x : liczby)
            v.push_back(x);

        auto koniec = high_resolution_clock::now();

        cout << "VECTOR\n";
        cout << "Wstawienie 100000: "
             << duration_cast<milliseconds>(koniec - start).count()
             << " ms\n";

        start = high_resolution_clock::now();

        sort(v.begin(), v.end());

        koniec = high_resolution_clock::now();

        cout << "Sortowanie: "
             << duration_cast<milliseconds>(koniec - start).count()
             << " ms\n";

        start = high_resolution_clock::now();

        for (int i = 0; i < K; i++)
            v.insert(v.begin() + 50000 + i, liczby[i]);

        koniec = high_resolution_clock::now();

        cout << "Wstawienie 50000 do srodka: "
             << duration_cast<milliseconds>(koniec - start).count()
             << " ms\n";

        start = high_resolution_clock::now();

        for (int i = 0; i < K; i++)
            v.erase(v.begin() + 50000);

        koniec = high_resolution_clock::now();

        cout << "Usuniecie 50000 ze srodka: "
             << duration_cast<milliseconds>(koniec - start).count()
             << " ms\n\n";
    }

    // TABLICA
    {
        int* tab = new int[N + K];

        auto start = high_resolution_clock::now();

        for (int i = 0; i < N; i++)
            tab[i] = liczby[i];

        auto koniec = high_resolution_clock::now();

        cout << "TABLICA\n";
        cout << "Wstawienie 100000: "
             << duration_cast<milliseconds>(koniec - start).count()
             << " ms\n";

        start = high_resolution_clock::now();

        sort(tab, tab + N);

        koniec = high_resolution_clock::now();

        cout << "Sortowanie: "
             << duration_cast<milliseconds>(koniec - start).count()
             << " ms\n";

        int rozmiar = N;

        start = high_resolution_clock::now();

        for (int i = 0; i < K; i++) {
            int pozycja = 50000 + i;

            for (int j = rozmiar; j > pozycja; j--)
                tab[j] = tab[j - 1];

            tab[pozycja] = liczby[i];
            rozmiar++;
        }

        koniec = high_resolution_clock::now();

        cout << "Wstawienie 50000 do srodka: "
             << duration_cast<milliseconds>(koniec - start).count()
             << " ms\n";

        start = high_resolution_clock::now();

        for (int i = 0; i < K; i++) {
            for (int j = 50000; j < rozmiar - 1; j++)
                tab[j] = tab[j + 1];

            rozmiar--;
        }

        koniec = high_resolution_clock::now();

        cout << "Usuniecie 50000 ze srodka: "
             << duration_cast<milliseconds>(koniec - start).count()
             << " ms\n\n";

        delete[] tab;
    }

    // STD::LIST
    {
        list<int> lista;

        auto start = high_resolution_clock::now();

        for (int x : liczby)
            lista.push_back(x);

        auto koniec = high_resolution_clock::now();

        cout << "STD::LIST\n";
        cout << "Wstawienie 100000: "
             << duration_cast<milliseconds>(koniec - start).count()
             << " ms\n";

        start = high_resolution_clock::now();

        lista.sort();

        koniec = high_resolution_clock::now();

        cout << "Sortowanie: "
             << duration_cast<milliseconds>(koniec - start).count()
             << " ms\n";

        auto it = lista.begin();
        advance(it, 50000);

        start = high_resolution_clock::now();

        for (int i = 0; i < K; i++) {
            it = lista.insert(it, liczby[i]);
            ++it;
        }

        koniec = high_resolution_clock::now();

        cout << "Wstawienie 50000 do srodka: "
             << duration_cast<milliseconds>(koniec - start).count()
             << " ms\n";

        it = lista.begin();
        advance(it, 50000);

        start = high_resolution_clock::now();

        for (int i = 0; i < K; i++)
            it = lista.erase(it);

        koniec = high_resolution_clock::now();

        cout << "Usuniecie 50000 ze srodka: "
             << duration_cast<milliseconds>(koniec - start).count()
             << " ms\n";
    }

    return 0;
}
