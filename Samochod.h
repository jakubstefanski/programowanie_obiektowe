#ifndef SAMOCHOD_H
#define SAMOCHOD_H

#include <iostream>
#include <string>
using namespace std;

class Samochod {
private:
    string marka;
    string model;
    int rocznik;
    string numer_VIN;
    bool stan_baku;
    double stawka_dobowa;
    bool czy_dostepny;

public:
    Samochod(string m, string mod, int r, string vin, bool stan, double stawka, bool dostepny) {
        marka = m;
        model = mod;
        rocznik = r;
        numer_VIN = vin;
        stan_baku = stan;
        stawka_dobowa = stawka;
        czy_dostepny = dostepny;
    }

    string getMarka() { 
        return marka; 
    }
    void setMarka(string m) {
         marka = m; 
    }

    string getModel() { 
        return model; 
    }
    void setModel(string mod) {
         model = mod; 
    }

    int getRocznik() { 
        return rocznik; 
    }
    void setRocznik(int r) {
         rocznik = r; 
    }

    string getNumerVIN() { 
        return numer_VIN; 
    }
    void setNumerVIN(string vin) {
         numer_VIN = vin; 
    }

    bool getStanBaku() { 
        return stan_baku; 
    }
    void setStanBaku(bool stan) {
         stan_baku = stan; 
    }

    double getStawkaDobowa() { 
        return stawka_dobowa; 
    }
    void setStawkaDobowa(double stawka) {
         stawka_dobowa = stawka; 
        }

    bool getCzyDostepny() { 
        return czy_dostepny; 
    }
    void setCzyDostepny(bool dostepny) { 
        czy_dostepny = dostepny; 
    }
};

#endif