#ifndef POZYCJA_WYPOZYCZENIA_H
#define POZYCJA_WYPOZYCZENIA_H

#include "Samochod.h"

class PozycjaWypozyczenia {
private:
    Samochod samochod;

public:
    PozycjaWypozyczenia(Samochod s);

    Samochod getSamochod();
    void setSamochod(Samochod s);
};

#endif
