
#include <iostream>
#include <string>

using namespace std;

template <typename T>
void wypisz(T zmienna)
{
    cout << zmienna << endl;
}

int main()
{
    int a = 10;
    string tekst = "Hello";
    double b = 3.14;
    char znak = 'A';
    bool logiczna = true;

    wypisz(a);
    wypisz(tekst);
    wypisz(b);
    wypisz(znak);
    wypisz(logiczna);

    return 0;
}
