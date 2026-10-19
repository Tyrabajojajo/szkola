
#include <iostream>
#include "bateria.h"

using namespace std;

void sprawdzPaliwo(Samochod s, double km) {
    double potrzebnePaliwo = km * s.spalanie / 100.0;

    cout << "Czy samochod ma wystarczajaco paliwa na "
         << km << " km?" << endl;

    if (s.paliwo >= potrzebnePaliwo) {
        cout << "Tak, wystarczy paliwa." << endl;
    } else {
        cout << "Nie, brakuje paliwa." << endl;
    }

    cout << "Potrzebne paliwo: " << potrzebnePaliwo
         << " litrow" << endl;
    cout << "Dostepne paliwo: " << s.paliwo
         << " litrow" << endl;
    cout << "------------------------" << endl;
}

int main() {
    Samochod s1("Toyota", "Corolla", 1.6, 6.5, 40);
    Samochod s2("BMW", "320d", 2.0, 5.5, 10);
    Samochod s3("Fiat", "Panda", 1.2, 5.0, 30);

    sprawdzPaliwo(s1, 500);
    sprawdzPaliwo(s2, 300);
    sprawdzPaliwo(s3, 400);

    return 0;
}
