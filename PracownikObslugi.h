#ifndef PRACOWNIK_OBSLUGI_H
#define PRACOWNIK_OBSLUGI_H

#include "Uzytkownik.h"

class PracownikObslugi : public Uzytkownik {
private:
    int numer_pracowniczy;
    double pensja;

public:
    PracownikObslugi(string i, string n, int nr, string p, int nr_prac, double pen)
        : Uzytkownik(i, n, nr, p) {
        numer_pracowniczy = nr_prac;
        pensja = pen;
    }
    
    int getNumerPracowniczy() {
        return numer_pracowniczy;
    }
    void setNumerPracowniczy(int nr) {
        numer_pracowniczy = nr;
    }

    double getPensja() {
        return pensja;
    }
    void setPensja(double pen) {
        pensja = pen;
    }
};

#endif