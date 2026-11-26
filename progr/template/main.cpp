#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Szablon dla pojedynczych zmiennych
template <typename T>
void wypisz(T zmienna)
{
    cout << zmienna << endl;
}

// Przeci¹¿enie szablonu dla std::vector
template <typename T>
void wypisz(const vector<T>& wektor)
{
    cout << "Vector: [ ";
    for (const auto& element : wektor) {
        cout << element << " ";
    }
    cout << "]" << endl;
}

// Przeci¹¿enie szablonu dla zwyk³ych tablic C++ (statycznych)
template <typename T, size_t N>
void wypisz(T (&tablica)[N])
{
    cout << "Tablica: [ ";
    for (size_t i = 0; i < N; ++i) {
        cout << tablica[i] << " ";
    }
    cout << "]" << endl;
}

int main()
{
    int a = 10;
    string tekst = "Hello";
    double b = 3.14;
    char znak = 'A';
    bool logiczna = true;

    // Dodany wektor
    vector<int> moj_wektor = {1, 2, 3, 4, 5};

    // Dodana zwyk³a tablica
    int moja_tablica[] = {10, 20, 30, 40};

    wypisz(a);
    wypisz(tekst);
    wypisz(b);
    wypisz(znak);
    wypisz(logiczna);

    // Wywo³anie dla wektora i tablicy
    wypisz(moj_wektor);
    wypisz(moja_tablica);

    return 0;
}
