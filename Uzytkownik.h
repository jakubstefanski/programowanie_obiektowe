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
    Uzytkownik(string i, string n, int nr, string p) {
        imie = i;
        nazwisko = n;
        numer_identyfikujacy = nr;
        Pesel = p;
    }

    
    string getImie() {
        return imie;
    }
    void setImie(string i) {
        imie = i;
    }
    
    string getNazwisko() {
        return nazwisko;
    }
    void setNazwisko(string n) {
        nazwisko = n;
    }

    int getNumerIdentyfikujacy() {
        return numer_identyfikujacy;
    }
    void setNumerIdentyfikujacy(int nr) {
        numer_identyfikujacy = nr;
    }

    string getPesel() {
        return Pesel;
    }
    void setPesel(string p) {
        Pesel = p;
    }
};

#endif