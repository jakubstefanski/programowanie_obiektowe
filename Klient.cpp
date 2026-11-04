#include "Klient.h"

Klient::Klient(string i, string n, int nr, string p)
    : Uzytkownik(i, n, nr, p) {
}

Konto& Klient::getKonto() {
    return konto;
}

void Klient::setKonto(Konto k) {
    konto = k;
}

