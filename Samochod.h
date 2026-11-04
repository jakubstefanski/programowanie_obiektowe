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
    Samochod(string m, string mod, int r, string vin, bool stan, double stawka, bool dostepny);

    string getMarka();
    void setMarka(string m);

    string getModel();
    void setModel(string mod);

    int getRocznik();
    void setRocznik(int r);

    string getNumerVIN();
    void setNumerVIN(string vin);

    bool getStanBaku();
    void setStanBaku(bool stan);

    double getStawkaDobowa();
    void setStawkaDobowa(double stawka);

    bool getCzyDostepny();
    void setCzyDostepny(bool dostepny);
};

#endif
