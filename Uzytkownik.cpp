#include "Uzytkownik.h"

Uzytkownik::Uzytkownik(string i, string n, int nr, string p) {
    imie = i;
    nazwisko = n;
    numer_identyfikujacy = nr;
    Pesel = p;
}

string Uzytkownik::getImie() {
    return imie;
}

void Uzytkownik::setImie(string i) {
    imie = i;
}

string Uzytkownik::getNazwisko() {
    return nazwisko;
}

void Uzytkownik::setNazwisko(string n) {
    nazwisko = n;
}

int Uzytkownik::getNumerIdentyfikujacy() {
    return numer_identyfikujacy;
}

void Uzytkownik::setNumerIdentyfikujacy(int nr) {
    numer_identyfikujacy = nr;
}

string Uzytkownik::getPesel() {
    return Pesel;
}

void Uzytkownik::setPesel(string p) {
    Pesel = p;
}
