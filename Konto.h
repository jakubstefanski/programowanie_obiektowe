#ifndef KONTO_H
#define KONTO_H

#include "Wypozyczenie.h"
#include <iostream>
#include <vector>
using namespace std;

class Konto {
private:
    int liczba_wypozyczonych_aut;
    double kara;
    vector<Wypozyczenie> lista_wypozyczen;

public:
    Konto();
    int getLiczbaWypozyczonychAut();
    double getKara();
    
    void dodajKare(double k);
    void dodajWypozyczenie(Wypozyczenie w);
    void usunWypozyczenie(Wypozyczenie w);

    vector<Wypozyczenie>& getListaWypozyczen();
    const vector<Wypozyczenie>& getListaWypozyczen() const;
};

#endif
