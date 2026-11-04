#ifndef PRACOWNIK_OBSLUGI_H
#define PRACOWNIK_OBSLUGI_H

#include "Uzytkownik.h"

class PracownikObslugi : public Uzytkownik {
private:
    int numer_pracowniczy;
    double pensja;

public:
    PracownikObslugi(string i, string n, int nr, string p, int nr_prac, double pen);
    
    int getNumerPracowniczy();
    void setNumerPracowniczy(int nr);

    double getPensja();
    void setPensja(double pen);
};

#endif
