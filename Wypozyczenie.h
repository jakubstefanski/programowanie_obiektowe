#ifndef WYPOZYCZENIE_H
#define WYPOZYCZENIE_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "PozycjaWypozyczenia.h"
using namespace std;

class Wypozyczenie {
private:
    string data_wypozyczenia; // Format: "YYYY-MM-DD"
    string data_zwrotu; // Format: "YYYY-MM-DD"
    string faktyczna_data_zwrotu; // Format: "YYYY-MM-DD"
    string status;
    double kaucja_zwrotna;
    double kwota_transakcji;
    vector<PozycjaWypozyczenia> pozycje;

    //Obliczenie ile dni mineło
    int obliczDni(string start, string koniec);

public:
    Wypozyczenie(string data_wyp, string data_zwr, double kaucja = 0.0);
    void dodajPozycje(PozycjaWypozyczenia p);

    vector<PozycjaWypozyczenia>& getPozycje();
    string getdata_wypozyczenia();
    string getdata_zwrotu();
    string getfaktdata_zwrotu();
    string getStatus();
    void setStatus(string s);
    double getKaucja();
    double getKwota();

    double kalkulujCene();
};

#endif
