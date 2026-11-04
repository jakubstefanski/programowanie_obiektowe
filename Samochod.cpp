#include "Samochod.h"

Samochod::Samochod(string m, string mod, int r, string vin, bool stan, double stawka, bool dostepny) {
    marka = m;
    model = mod;
    rocznik = r;
    numer_VIN = vin;
    stan_baku = stan;
    stawka_dobowa = stawka;
    czy_dostepny = dostepny;
}

string Samochod::getMarka() { 
    return marka; 
}

void Samochod::setMarka(string m) {
    marka = m; 
}

string Samochod::getModel() { 
    return model; 
}

void Samochod::setModel(string mod) {
    model = mod; 
}

int Samochod::getRocznik() { 
    return rocznik; 
}

void Samochod::setRocznik(int r) {
    rocznik = r; 
}

string Samochod::getNumerVIN() { 
    return numer_VIN; 
}

void Samochod::setNumerVIN(string vin) {
    numer_VIN = vin; 
}

bool Samochod::getStanBaku() { 
    return stan_baku; 
}

void Samochod::setStanBaku(bool stan) {
    stan_baku = stan; 
}

double Samochod::getStawkaDobowa() { 
    return stawka_dobowa; 
}

void Samochod::setStawkaDobowa(double stawka) {
    stawka_dobowa = stawka; 
}

bool Samochod::getCzyDostepny() { 
    return czy_dostepny; 
}

void Samochod::setCzyDostepny(bool dostepny) { 
    czy_dostepny = dostepny; 
}

