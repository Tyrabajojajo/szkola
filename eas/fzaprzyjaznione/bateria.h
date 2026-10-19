
#ifndef SAMOCHOD_H
#define SAMOCHOD_H

#include <string>
using namespace std;

class Samochod {
private:
    string marka;
    string model;
    double pojemnosc;
    double spalanie;
    double paliwo;

public:
    Samochod(string ma, string mo, double poj,
             double sp, double pal);

    friend void sprawdzPaliwo(Samochod s, double km);
};

#endif
