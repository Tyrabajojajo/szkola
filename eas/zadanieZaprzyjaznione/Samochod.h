#ifndef SAMOCHOD_H
#define SAMOCHOD_H

#include Pojazd.h

using namespace std;

class Samochod: public Pojazd{
private:
    int liczba_drzwi;
    bool automatyczna_skrzynia;

protected:
    void wypisz(ostream& os) const override{
        os << "Typ samochod\n";
        Pojazd::wypisz(os);
        os << "Liczba drzwi: " << liczba_drzwi << '\n'
           << "Automatyczna skrzynia: "
           << (automatyczna_skrzynia ? "tak" : "nie") << '\n';
    }
    public:
    Samochod(const string& marka,
             const string& model,
             int rok,
             int drzwi,
             bool automat)
        : Pojazd(marka, model, rok),
          liczba_drzwi(drzwi),
          automatyczna_skrzynia(automat) {
        setLiczbaDrzwi(drzwi);
    }

    int getLiczbaDrzwi() const {
        return liczba_drzwi;
    }

    bool getAutomatycznaSkrzynia() const {
        return automatyczna_skrzynia;
    }

    void setLiczbaDrzwi(int drzwi) {
        if (drzwi < 2 || drzwi > 7)
            throw sinvalid_argument("Nieprawidlowa liczba drzwi.");
        liczba_drzwi = drzwi;
    }

    void setAutomatycznaSkrzynia(bool automat) {
        automatyczna_skrzynia = automat;
    }

    friend ostream& operator<<(ostream& os,
                                    const Samochod& s) {
        s.wypisz(os);
        return os;
    }
};

#endif // SAMOCHOD_H_INCLUDED
