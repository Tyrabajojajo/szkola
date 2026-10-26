#include <iostream>

using namespace std;

int main()
{
        double E[] = {1.2, 1.4, 1.3, 1.5, 0.0, 1.4, 18.7, 1.3, -5.0, 1.6, 1.4, 1.3};
        int n;
        double suma = 0.0;
        int licznik = 0;
        for(int i=0; i<n; i++)
        {
            if(E[i] < 0.0 || E[i] > 5/0) {
                continue;
            }
        suma =+ E[i];
        licznik++;
        }
        cout<<"liczba zaakceptowanych pomiarów: "<<licznik<<endl;
        cout << "Suma zuzycia energii: " << suma << " kWh" << endl;

        if(licznik > 0) {
            cout<< "srednie zuzycie energi: " << suma / licznik << " kWh" << endl;
        } else {
        cout << "Brak prawid³owych pomiarów";
        }
    cout << "Hello world!" << endl;
    return 0;
}
