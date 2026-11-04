#include "Konto.h"

Konto::Konto() {
    liczba_wypozyczonych_aut = 0;
    kara = 0.0;
}

int Konto::getLiczbaWypozyczonychAut() {
    return liczba_wypozyczonych_aut;
}

double Konto::getKara() {
    return kara;
}

void Konto::dodajKare(double k) {
    kara += k;
}

void Konto::dodajWypozyczenie(Wypozyczenie w) {
    lista_wypozyczen.push_back(w);
    liczba_wypozyczonych_aut += w.getPozycje().size();
}

void Konto::usunWypozyczenie(Wypozyczenie w) {
    for (size_t i = 0; i < lista_wypozyczen.size(); i++) {
        if (lista_wypozyczen[i].getdata_wypozyczenia() == w.getdata_wypozyczenia() &&
            lista_wypozyczen[i].getdata_zwrotu() == w.getdata_zwrotu()) {
            
            liczba_wypozyczonych_aut -= lista_wypozyczen[i].getPozycje().size();
            lista_wypozyczen.erase(lista_wypozyczen.begin() + i);
            break;
        }
    }
}

vector<Wypozyczenie>& Konto::getListaWypozyczen() {
    return lista_wypozyczen;
}

const vector<Wypozyczenie>& Konto::getListaWypozyczen() const {
    return lista_wypozyczen;
}

