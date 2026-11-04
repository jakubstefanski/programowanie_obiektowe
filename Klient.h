#ifndef KLIENT_H
#define KLIENT_H

#include "Uzytkownik.h"
#include "Konto.h"

class Klient : public Uzytkownik {
private:
    Konto konto;
public:
    Klient(string i, string n, int nr, string p);

    Konto& getKonto();
    void setKonto(Konto k);
};
#endif
