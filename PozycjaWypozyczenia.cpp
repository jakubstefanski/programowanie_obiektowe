#include "PozycjaWypozyczenia.h"

PozycjaWypozyczenia::PozycjaWypozyczenia(Samochod s) : samochod(s) {
}

Samochod PozycjaWypozyczenia::getSamochod() {
    return samochod;
}

void PozycjaWypozyczenia::setSamochod(Samochod s) {
    samochod = s;
}

