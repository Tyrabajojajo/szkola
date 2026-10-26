#ifndef MOTOCYKL_H
#define MOTOCYKL_H

#include "Pojazd.h"

using namespace std;

class Motocykl : public Pojazd {
private:
    string typ;
    int pojemnosc_cc;

protected:
    void wypisz(ostream& os) const override {
        os << "Typ: Motocykl\n";
        Pojazd::wypisz(os);
        os << "Rodzaj motocykla: " << typ << '\n'
           << "Pojemnosc silnika: " << pojemnosc_cc
           << " cm3\n";
    }

public:
    Motocykl(const string& marka,
             const string& model,
             int rok,
             const string& typ,
             int pojemnosc)
        : Pojazd(marka, model, rok),
          typ(typ),
          pojemnosc_cc(pojemnosc) {
        setTyp(typ);
        setPojemnoscCC(pojemnosc);
    }

    string getTyp() const {
        return typ;
    }

    int getPojemnoscCC() const {
        return pojemnosc_cc;
    }

    void setTyp(const string& nowyTyp) {
        if (nowyTyp.empty())
            throw invalid_argument("Typ nie moze byc pusty.");
        typ = nowyTyp;
    }

    void setPojemnoscCC(int pojemnosc) {
        if (pojemnosc < 1 || pojemnosc > 3000)
            throw invalid_argument("Nieprawidlowa pojemnosc silnika.");
        pojemnosc_cc = pojemnosc;
    }

    friend ostream& operator<<(ostream& os,
                                    const Motocykl& m) {
        m.wypisz(os);
        return os;
    }
};

#endif
