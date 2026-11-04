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
    Platnosc(string d, double k, bool s);

    string getDataTransakcji();
    void setDataTransakcji(string d);

    double getKwota();
    void setKwota(double k);

    bool getStatus();
    void setStatus(bool s);
};

#endif
