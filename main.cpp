#include <iostream>
#include "Uzytkownik.h" 
#include "Konto.h"
#include "Klient.h"

int main() {
    //TEST CZY KLASA KLIENT DZIALA
    Klient klient("Jan", "Kowalski", 1, "90010112345");
    cout << "Imie: " << klient.getImie() << endl;
    cout << "Nazwisko: " << klient.getNazwisko() << endl;
    cout << "Numer identyfikujacy: " << klient.getNumerIdentyfikujacy() << endl;
    cout << "Pesel: " << klient.getPesel() << endl;
    klient.getKonto().dodajKare(50.0);
    cout << "Akutalna kara: " << klient.getKonto().getKara() << endl;

}