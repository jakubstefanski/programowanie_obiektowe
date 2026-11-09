#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <vector>
#include <ctime>
#include "Klient.h"
#include "PracownikObslugi.h"
#include "Wypozyczenie.h"
#include "Samochod.h"
#include "Platnosc.h"

using namespace std;

class SystemRezerwacjiPojazdow {
private:
    vector<Klient> lista_klientow;                   
    vector<PracownikObslugi> lista_pracownikow;     
    vector<Wypozyczenie> lista_wypozyczen;           
    vector<Samochod> samochody;                   

public:
    SystemRezerwacjiPojazdow();

    void dodajKlienta(Klient k);
    void dodajPracownika(PracownikObslugi p);
    void dodajWypozyczenie(Wypozyczenie w);
    void dodajSamochod(Samochod s);
   
    vector<Klient>& getListaKlientow();
    vector<PracownikObslugi>& getListaPracownikow();
    vector<Wypozyczenie>& getListaWypozyczen();
    vector<Samochod>& getSamochody();

    void Wypozycz(int numer_identyfikujacy_klienta, Samochod auto_wypozyczane, string od_kiedy, string do_kiedy);
    void WyswietlListeDostepnychAutpoNazwie(Samochod tekst);
    void Dodajsamochod(int numer_identyfikujacy_pracownika_obslugi, Samochod samochod);
    Platnosc OplacRezerwacje(Wypozyczenie& rezerwacja);
    void naliczKare(int numer_identyfikujacy_klienta, double kwota);
    void naliczKarePrzezPracownika(int id_pracownika, int id_klienta, double kwota);
};

#endif
