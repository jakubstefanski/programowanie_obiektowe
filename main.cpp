#include <iostream>
#include <string>
#include <vector>
#include "Uzytkownik.h" 
#include "Konto.h"
#include "Klient.h"
#include "System.h"
#include "Samochod.h"

using namespace std;

int main() {
    SystemRezerwacjiPojazdow system;
    Samochod auto1("Toyota", "Corolla", 2021, "VIN11111", true, 150.0, true);
    Samochod auto2("BMW", "Seria 3", 2022, "VIN22222", true, 280.0, true);
    system.dodajSamochod(auto1);
    system.dodajSamochod(auto2);

    // TEST CZY KLASA KLIENT DZIALA
    Klient klient1("Jan", "Kowalski", 1, "90010112345");
    Klient klient2("Anna", "Nowak", 2, "95020254321");
    system.dodajKlienta(klient1);
    system.dodajKlienta(klient2);

    cout << "Imie: " << klient1.getImie() << endl;
    cout << "Nazwisko: " << klient1.getNazwisko() << endl;
    cout << "Numer identyfikujacy: " << klient1.getNumerIdentyfikujacy() << endl;
    cout << "Pesel: " << klient1.getPesel() << endl;
    klient1.getKonto().dodajKare(50.0);
    cout << "Akutalna kara: " << klient1.getKonto().getKara() << endl;

    // LOGOWANIE NA KONTO (przeszukiwanie wszystkich klientow w systemie)
    cout << "\n========================================" << endl;
    cout << "          LOGOWANIE NA KONTO            " << endl;
    cout << "========================================" << endl;

    string podaneImie;
    string podanyPesel;
    Klient* zalogowanyKlient = nullptr;

    while (zalogowanyKlient == nullptr) {
        cout << "Podaj imie: ";
        cin >> podaneImie;
        cout << "Podaj PESEL: ";
        cin >> podanyPesel;

        // Przeszukanie listy klientow zarejestrowanych w systemie
        vector<Klient>& klienci = system.getListaKlientow();
        for (size_t i = 0; i < klienci.size(); i++) {
            if (klienci[i].getImie() == podaneImie && klienci[i].getPesel() == podanyPesel) {
                zalogowanyKlient = &klienci[i];
                break;
            }
        }

        if (zalogowanyKlient != nullptr) {
            cout << "\nLogowanie udane! Witaj, " << zalogowanyKlient->getImie() << " " << zalogowanyKlient->getNazwisko() << "!" << endl;
        } else {
            cout << "\nBlad: Niepoprawne imie lub PESEL. Sprobuj ponownie.\n" << endl;
        }
    }

    // MENU GLOWNE
    int wybor = 0;
    do {
        cout << "\n========================================" << endl;
        cout << "              MENU GLOWNE               " << endl;
        cout << "========================================" << endl;
        cout << "1. Wyszukaj auto" << endl;
        cout << "2. Poznaj cene wynajmu" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Wybierz opcje: ";
        cin >> wybor;

        if (wybor == 1) {
            string szukanaNazwa;
            cout << "Podaj nazwe auta (marka lub model): ";
            cin >> ws;
            getline(cin, szukanaNazwa);
            Samochod szukany(szukanaNazwa, szukanaNazwa, 0, "", false, 0.0, false);
            system.WyswietlListeDostepnychAutpoNazwie(szukany);
        } else if (wybor == 2) {
            vector<Samochod>& auta = system.getSamochody();
            if (auta.empty()) {
                cout << "\nBrak samochodow w systemie." << endl;
            } else {
                cout << "\n--- LISTA SAMOCHODOW DO KALKULACJI ---" << endl;
                for (size_t i = 0; i < auta.size(); i++) {
                    cout << "  [" << i + 1 << "] " << auta[i].getMarka() << " " << auta[i].getModel()
                         << " (Stawka: " << auta[i].getStawkaDobowa() << " zl/doba)" << endl;
                }

                int nrAuta;
                cout << "Wybierz numer auta (1-" << auta.size() << "): ";
                cin >> nrAuta;

                if (nrAuta >= 1 && nrAuta <= static_cast<int>(auta.size())) {
                    Samochod& wybraneAuto = auta[nrAuta - 1];

                    string od_kiedy, do_kiedy;
                    cout << "Podaj date rozpoczecia wynajmu (YYYY-MM-DD): ";
                    cin >> od_kiedy;
                    cout << "Podaj date zakonczenia wynajmu (YYYY-MM-DD): ";
                    cin >> do_kiedy;

                    PozycjaWypozyczenia pozycja(wybraneAuto);
                    Wypozyczenie kalkulacja(od_kiedy, do_kiedy);
                    kalkulacja.dodajPozycje(pozycja);

                    double cena = kalkulacja.kalkulujCene();
                    double kaucja = kalkulacja.getKaucja();

                    cout << "       KALKULACJA CENY WYNAJMU:          " << endl;
                    cout << "Pojazd: " << wybraneAuto.getMarka() << " " << wybraneAuto.getModel() << endl;
                    cout << "Stawka dobowa: " << wybraneAuto.getStawkaDobowa() << " zl/doba" << endl;
                    cout << "Okres wynajmu: " << od_kiedy << " do " << do_kiedy << endl;
                    cout << "Szacowany koszt wynajmu: " << cena << " zl" << endl;
                    cout << "Wymagana kaucja zwrotna: " << kaucja << " zl" << endl;
                } else {
                    cout << "\nBlad: Niepoprawny numer samochodu!" << endl;
                }
            }
        } else if (wybor == 0) {
            cout << "Wylogowano z systemu. Do widzenia!" << endl;
        } else {
            cout << "Niepoprawna opcja! Sprobuj ponownie." << endl;
        }
    } while (wybor != 0);

    return 0;
}
