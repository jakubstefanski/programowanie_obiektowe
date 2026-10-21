#ifndef WYPOZYCZENIE_H
#define WYPOZYCZENIE_H

#include <iostream>
#include <string>
using namespace std;

class Wypozyczenie{
private:
    string data_wypozyczenia;
    string data_zwrotu;
    string faktyczna_data_zwrotu;
    string status;
    double kaucja_zwrotna;
    double kwota_transakcji;

public:
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


    void kalkulujCene()
    {

    }
};

#endif