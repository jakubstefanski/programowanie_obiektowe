#ifndef WYPOZYCZENIE_H
#define WYPOZYCZENIE_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "PozycjaWypozyczenia.h"
using namespace std;

class Wypozyczenie{
private:
    string data_wypozyczenia; // Format: "YYYY-MM-DD"
    string data_zwrotu; // Format: "YYYY-MM-DD"
    string faktyczna_data_zwrotu; // Format: "YYYY-MM-DD"
    string status;
    double kaucja_zwrotna;
    double kwota_transakcji;
    vector<PozycjaWypozyczenia> pozycje;

    //Obliczenie ile dni mineło
    int obliczDni(string start, string koniec) {
        tm t1 = {};
        tm t2 = {};

        t1.tm_year = stoi(start.substr(0, 4)) - 1900;
        t1.tm_mon  = stoi(start.substr(5, 2)) - 1;
        t1.tm_mday = stoi(start.substr(8, 2));

        t2.tm_year = stoi(koniec.substr(0, 4)) - 1900;
        t2.tm_mon  = stoi(koniec.substr(5, 2)) - 1;
        t2.tm_mday = stoi(koniec.substr(8, 2));

        time_t czas1 = mktime(&t1);
        time_t czas2 = mktime(&t2);

        double roznica_sekund = difftime(czas2, czas1);
        int dni = roznica_sekund / 86400;

        return dni > 0 ? dni : 1; 
    }
public:
    Wypozyczenie(string data_wyp, string data_zwr, double kaucja = 0.0) {
        data_wypozyczenia = data_wyp;
        data_zwrotu = data_zwr;
        faktyczna_data_zwrotu = "";
        status = "Nowe";
        kaucja_zwrotna = kaucja;
        kwota_transakcji = 0.0;
    }
    void dodajPozycje(PozycjaWypozyczenia p) {
        pozycje.push_back(p);
    }

    vector<PozycjaWypozyczenia>& getPozycje() {
        return pozycje;
    }
    string getdata_wypozyczenia()
    {
        return data_wypozyczenia;
    }

    string getdata_zwrotu()
    {
        return data_zwrotu;
    }
    string getfaktdata_zwrotu()
    {
        return faktyczna_data_zwrotu;
    }
    string getStatus()
    {
        return status;
    }
    double getKaucja()
    {
        return kaucja_zwrotna;
    }
    double getKwota()
    {
        return kwota_transakcji;
    }


    double kalkulujCene()
    {
        int dni = obliczDni(data_wypozyczenia, data_zwrotu);
        kwota_transakcji = 0.0;

        for (int i = 0; i < pozycje.size(); i++) {
            kwota_transakcji += dni * pozycje[i].getSamochod().getStawkaDobowa(); 
        }

        return kwota_transakcji;
    }
};

#endif