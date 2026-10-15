#ifndef KLIENT_H
#define KLIENT_H

#include "Uzytkownik.h"
#include "Konto.h"

class Klient : public Uzytkownik {
private:
    Konto konto;
public:
    Klient(string i, string n, int nr, string p)
        : Uzytkownik(i, n, nr, p) {
    }

    Konto& getKonto() {
        return konto;
    }
    void setKonto(Konto k) {
        konto = k;
    }
};
#endif