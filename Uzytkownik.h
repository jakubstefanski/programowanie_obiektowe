#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>
#include <string>
using namespace std;

class Uzytkownik {
private:
    string imie;
    string nazwisko;
    int numer_identyfikujacy;
    string Pesel;

public:
    Uzytkownik(string i, string n, int nr, string p);

    string getImie();
    void setImie(string i);

    string getNazwisko();
    void setNazwisko(string n);

    int getNumerIdentyfikujacy();
    void setNumerIdentyfikujacy(int nr);

    string getPesel();
    void setPesel(string p);
};

#endif
