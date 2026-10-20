#ifndef KONTO_H
#define KONTO_H

#include <iostream>
using namespace std;

//w klasie brakuje funkcjonalności metody dodaj i usuń wypożyczenie

class Konto {
private:
    int liczba_wypozyczonych_aut;
    double kara;

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

    void dodajWypozyczenie() {
        
    }

    void usunWypozyczenie() {
       
    }
};

#endif