#include "System.h"

SystemRezerwacjiPojazdow::SystemRezerwacjiPojazdow() {}

void SystemRezerwacjiPojazdow::dodajKlienta(Klient k) {
    lista_klientow.push_back(k);
}

void SystemRezerwacjiPojazdow::dodajPracownika(PracownikObslugi p) {
    lista_pracownikow.push_back(p);
}

void SystemRezerwacjiPojazdow::dodajWypozyczenie(Wypozyczenie w) {
    lista_wypozyczen.push_back(w);
}

void SystemRezerwacjiPojazdow::dodajSamochod(Samochod s) {
    samochody.push_back(s);
}

vector<Klient>& SystemRezerwacjiPojazdow::getListaKlientow() {
    return lista_klientow;
}

vector<PracownikObslugi>& SystemRezerwacjiPojazdow::getListaPracownikow() {
    return lista_pracownikow;
}

vector<Wypozyczenie>& SystemRezerwacjiPojazdow::getListaWypozyczen() {
    return lista_wypozyczen;
}

vector<Samochod>& SystemRezerwacjiPojazdow::getSamochody() {
    return samochody;
}

void SystemRezerwacjiPojazdow::Wypozycz(int numer_identyfikujacy_klienta, Samochod auto_wypozyczane, string od_kiedy, string do_kiedy) {
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

void SystemRezerwacjiPojazdow::WyswietlListeDostepnychAutpoNazwie(Samochod tekst) {
    cout << "Dostepne samochody dla: " << tekst.getMarka() << " " << tekst.getModel() << endl;
    bool znaleziono = false;
    for (int i = 0; i < samochody.size(); i++) {
        if (samochody[i].getCzyDostepny() == true &&
           (samochody[i].getMarka() == tekst.getMarka() || samochody[i].getModel() == tekst.getModel())) {
            
            cout << samochody[i].getMarka() << " " << samochody[i].getModel()
                 << "Rocznik: " << samochody[i].getRocznik()
                 << "VIN: " << samochody[i].getNumerVIN()
                 << "Stawka: " << samochody[i].getStawkaDobowa() << " zl/doba" << endl;
            znaleziono = true;
        }
    }

    if (znaleziono == false) {
        cout << "Brak dostepnych samochodow o podanej nazwie." << endl;
    }
}

void SystemRezerwacjiPojazdow::Dodajsamochod(int numer_identyfikujacy_pracownika_obslugi, Samochod samochod) {
    for (int i = 0; i < lista_pracownikow.size(); i++) {
        if (lista_pracownikow[i].getNumerIdentyfikujacy() == numer_identyfikujacy_pracownika_obslugi) {
            samochody.push_back(samochod);
            cout << "Pracownik o ID: " << numer_identyfikujacy_pracownika_obslugi 
                 << " dodal samochod: " << samochod.getMarka() << " " << samochod.getModel() << endl;
            return;
        }
    }
    cout << "Blad: Brak uprawnien. Nie znaleziono pracownika o ID: " << numer_identyfikujacy_pracownika_obslugi << endl;
}

void SystemRezerwacjiPojazdow::naliczKare(int numer_identyfikujacy_klienta, double kwota) {
    if (kwota <= 0) {
        cout << "Blad: Kwota kary musi byc wieksza od zera!" << endl;
        return;
    }

    for (size_t i = 0; i < lista_klientow.size(); i++) {
        if (lista_klientow[i].getNumerIdentyfikujacy() == numer_identyfikujacy_klienta) {
            lista_klientow[i].getKonto().dodajKare(kwota);
            cout << "Naliczono kare klinetowi o id = " << numer_identyfikujacy_klienta << endl;
            return;
        }
    }
    cout << "Blad: Nie znaleziono klienta o ID: " << numer_identyfikujacy_klienta << "!" << endl;
}

void SystemRezerwacjiPojazdow::naliczKarePrzezPracownika(int id_pracownika, int id_klienta, double kwota) {
    bool pracownik_istnieje = false;
    for (size_t i = 0; i < lista_pracownikow.size(); i++) {
        if (lista_pracownikow[i].getNumerIdentyfikujacy() == id_pracownika) {
            pracownik_istnieje = true;
            break;
        }
    }

    if (!pracownik_istnieje) {
        cout << "Blad: Brak uprawnien. Nie znaleziono pracownika o ID: " << id_pracownika << endl;
        return;
    }

    naliczKare(id_klienta, kwota);
}
