#ifndef PLATNOSC_H
#define PLATNOSC_H

#include <string>
using namespace std;

class Platnosc {
private:
    string data_transakcji;
    double kwota;
    bool status;

public:
    Platnosc(string d, double k, bool s) {
        data_transakcji = d;
        kwota = k;
        status = s;
    }

    Platnosc(string data, double k, bool s) {
        data_transakcji = data;
        kwota = k;
        status = s;
    }

    string getDataTransakcji() { 
        return data_transakcji; 
    }
    void setDataTransakcji(string d) { 
        data_transakcji = d; 
    }

    double getKwota() { 
        return kwota; 
    }
    void setKwota(double k) {
         kwota = k; 
    }

    bool getStatus() {
         return status; 
    }
    void setStatus(bool s) { 
        status = s; 
    }
};

#endif