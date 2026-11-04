#include "PracownikObslugi.h"

PracownikObslugi::PracownikObslugi(string i, string n, int nr, string p, int nr_prac, double pen)
    : Uzytkownik(i, n, nr, p) {
    numer_pracowniczy = nr_prac;
    pensja = pen;
}

int PracownikObslugi::getNumerPracowniczy() {
    return numer_pracowniczy;
}

void PracownikObslugi::setNumerPracowniczy(int nr) {
    numer_pracowniczy = nr;
}

double PracownikObslugi::getPensja() {
    return pensja;
}

void PracownikObslugi::setPensja(double pen) {
    pensja = pen;
}

