#ifndef POZYCJA_WYPOZYCZENIA_H
#define POZYCJA_WYPOZYCZENIA_H

#include "Samochod.h"

class PozycjaWypozyczenia {
private:
    Samochod samochod;

public:
    PozycjaWypozyczenia(Samochod s) : samochod(s) {
    }

    Samochod getSamochod() {
        return samochod;
    }
    void setSamochod(Samochod s) {
        samochod = s;
    }
};

#endif