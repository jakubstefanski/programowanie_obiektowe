#include "Platnosc.h"

Platnosc::Platnosc(string d, double k, bool s) {
    data_transakcji = d;
    kwota = k;
    status = s;
}

string Platnosc::getDataTransakcji() { 
    return data_transakcji; 
}

void Platnosc::setDataTransakcji(string d) { 
    data_transakcji = d; 
}

double Platnosc::getKwota() { 
    return kwota; 
}

void Platnosc::setKwota(double k) { 
    kwota = k; 
}

bool Platnosc::getStatus() { 
    return status; 
}

void Platnosc::setStatus(bool s) { 
    status = s; 
}

