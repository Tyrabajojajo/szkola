#ifndef POJAZD_H
#define POJAZD_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Pojazd{
private:
    string marka;
    string model;
    int rokProdukcji;

protected:
    virtual void wypisz(ostream& os) const{
        os << "Marka: " << marka << '\n'
        << "Model: " << model << '\n'
        << "Rok produkcji: "<<rokProdukcji << '\n'
    }
public:
    Pojazd(const string& marka,
           const string& model,
           int rok)
        : marka(marka), model(model), rok_produkcji(rok) {
        setMarka(marka);
        setModel(model);
        setRokProdukcji(rok);
        }

        virtual ~Pojazd() = default;

        string getMarka() const {
            return marka;
        }
        string getModel() const{
            return model;
        }
        int getRokProdukcji() const{
            return rokProdukcji;
        }

        void setMarka(const string& nowaMarka){
            if(nowaMarka.empty())
                throw invalid_argument("marka nie moze byc pusta");
            marka = nowaMarka
        }
        void setModel(const string& nowyModel){
            if(nowyModel.empty())
                throw invalid_argument("model nie moze byc pusty");
            model = nowyModel
        }
        void setRokProdukcji(int rok){
            if(rok<1986 || rok>2100)
                throw invalid_argument("nieprawidlowy rok");
            rokProdukcji = rok;
        }

        friend std::ostream& operator<<(std::ostream& os,
                                    const Pojazd& p) {
        p.wypisz(os);
        return os;
    }
};

#endif // POJAZD_H_INCLUDED
