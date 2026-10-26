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
    Konto() {
        liczba_wypozyczonych_aut = 0;
        kara = 0.0;
    }
    int getLiczbaWypozyczonychAut() {
        return liczba_wypozyczonych_aut;
    }
    double getKara() {
        return kara;
    }
    
    void dodajKare(double k) {
        kara += k;
    }

    void dodajWypozyczenie(Wypozyczenie w) {
        lista_wypozyczen.push_back(w);
        liczba_wypozyczonych_aut += w.getPozycje().size();
    }

    void usunWypozyczenie(Wypozyczenie w) {
        for (size_t i = 0; i < lista_wypozyczen.size(); i++) {
            if (lista_wypozyczen[i].getdata_wypozyczenia() == w.getdata_wypozyczenia() &&
                lista_wypozyczen[i].getdata_zwrotu() == w.getdata_zwrotu()) {
                
                liczba_wypozyczonych_aut -= lista_wypozyczen[i].getPozycje().size();
                lista_wypozyczen.erase(lista_wypozyczen.begin() + i);
                break;
            }
        }
    }

    vector<Wypozyczenie>& getListaWypozyczen() {
        return lista_wypozyczen;
    }

    const vector<Wypozyczenie>& getListaWypozyczen() const {
        return lista_wypozyczen;
    }
};

#endif
