#include "Wypozyczenie.h"

// Obliczenie ile dni mineło
int Wypozyczenie::obliczDni(string start, string koniec) {
    tm t1 = {};
    tm t2 = {};

    t1.tm_year = stoi(start.substr(0, 4)) - 1900;
    t1.tm_mon  = stoi(start.substr(5, 2)) - 1;
    t1.tm_mday = stoi(start.substr(8, 2));

    t2.tm_year = stoi(koniec.substr(0, 4)) - 1900;
    t2.tm_mon  = stoi(koniec.substr(5, 2)) - 1;
    t2.tm_mday = stoi(koniec.substr(8, 2));

    time_t czas1 = mktime(&t1);
    time_t czas2 = mktime(&t2);

    double roznica_sekund = difftime(czas2, czas1);
    int dni = roznica_sekund / 86400;

    return dni > 0 ? dni : 1; 
}

Wypozyczenie::Wypozyczenie(string data_wyp, string data_zwr, double kaucja) {
    data_wypozyczenia = data_wyp;
    data_zwrotu = data_zwr;
    faktyczna_data_zwrotu = "";
    status = "Nowe";
    kaucja_zwrotna = kaucja;
    kwota_transakcji = 0.0;
}

void Wypozyczenie::dodajPozycje(PozycjaWypozyczenia p) {
    pozycje.push_back(p);
}

vector<PozycjaWypozyczenia>& Wypozyczenie::getPozycje() {
    return pozycje;
}

string Wypozyczenie::getdata_wypozyczenia() {
    return data_wypozyczenia;
}

string Wypozyczenie::getdata_zwrotu() {
    return data_zwrotu;
}

string Wypozyczenie::getfaktdata_zwrotu() {
    return faktyczna_data_zwrotu;
}

string Wypozyczenie::getStatus() {
    return status;
}

double Wypozyczenie::getKaucja() {
    return kaucja_zwrotna;
}

double Wypozyczenie::getKwota() {
    return kwota_transakcji;
}

double Wypozyczenie::kalkulujCene() {
    int dni = obliczDni(data_wypozyczenia, data_zwrotu);
    kwota_transakcji = 0.0;
    kaucja_zwrotna = 0.0;

    for (int i = 0; i < pozycje.size(); i++) {
        kwota_transakcji += dni * pozycje[i].getSamochod().getStawkaDobowa();
        kaucja_zwrotna += 3 * pozycje[i].getSamochod().getStawkaDobowa();
    }

    return kwota_transakcji;
}
