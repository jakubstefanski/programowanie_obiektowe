#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <vector>
#include "Klient.h"
#include "PracownikObslugi.h"
#include "Wypozyczenie.h"
#include "Samochod.h"

using namespace std;

class SystemRezerwacjiPojazdow {
private:
    vector<Klient> lista_klientow;                   
    vector<PracownikObslugi> lista_pracownikow;     
    vector<Wypozyczenie> lista_wypozyczen;           
    vector<Samochod> samochody;                   

public:
    SystemRezerwacjiPojazdow() {}


    void dodajKlienta(Klient k) {
        lista_klientow.push_back(k);
    }
    void dodajPracownika(PracownikObslugi p) {
        lista_pracownikow.push_back(p);
    }
    void dodajWypozyczenie(Wypozyczenie w) {
        lista_wypozyczen.push_back(w);
    }
    void dodajSamochod(Samochod s) {
        samochody.push_back(s);
    }
   
    vector<Klient>& getListaKlientow() {
        return lista_klientow;
    }
    vector<PracownikObslugi>& getListaPracownikow() {
        return lista_pracownikow;
    }

    vector<Wypozyczenie>& getListaWypozyczen() {
        return lista_wypozyczen;
    }
    vector<Samochod>& getSamochody() {
        return samochody;
    }

    void Wypozycz(int numer_identyfikujacy_klienta, Samochod auto_wypozyczane, string od_kiedy, string do_kiedy) {
        for (int i = 0; i < lista_klientow.size(); i++) {
            if (lista_klientow[i].getNumerIdentyfikujacy() == numer_identyfikujacy_klienta) {
                
                for (int j = 0; j < samochody.size(); j++) {
                    if (samochody[j].getNumerVIN() == auto_wypozyczane.getNumerVIN()) {
                        
                        if (samochody[j].getCzyDostepny() == true) {
                            samochody[j].setCzyDostepny(false);

                            PozycjaWypozyczenia pozycja(samochody[j]);
                            Wypozyczenie wyp(od_kiedy, do_kiedy);
                            wyp.dodajPozycje(pozycja);

                            wyp.kalkulujCene();

                            lista_klientow[i].getKonto().dodajWypozyczenie(wyp);
                            lista_wypozyczen.push_back(wyp);
                            
                            cout << "Wypozyczono auto na okres od " << od_kiedy << " do " << do_kiedy << "!" << endl;
                            cout << "Cena: " << wyp.getKwota() << " zl" << endl;
                            cout << "Kaucja zwrotna: " << wyp.getKaucja() << " zl" << endl;
                            return;
                        } else {
                            cout << "Auto jest zajete!" << endl;
                            return;
                        }
                    }
                }
                cout << "Nie znaleziono takiego auta!" << endl;
                return;
            }
        }
        cout << "Nie znaleziono klienta!" << endl;
    }
};

#endif