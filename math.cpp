// Vidurkiu skaiciavimas
#include "header.h"

// Apskaiciuojamas namu darbu rezultatu vidurkis
double Vidurkis(const vector<int>& namudarbas) {
    double sum = 0;
    for (int i = 0; i < namudarbas.size(); i++) {
        sum += namudarbas[i];
    }
    return sum / namudarbas.size();
}

// Apskaiciuojamas galutinis paprastas vidurkis
double GalutinisVid(const Studentas& duom) {
    double ndAverage = Vidurkis(duom.namudarbas);
    return 0.4 * ndAverage + 0.6 * duom.egzaminorez;
}

// Apskaiciuojama namu darbu rezultatu mediana
double Mediana(const vector<int>& namudarbas) {
    vector<int> sortedVector = namudarbas;
    sort(sortedVector.begin(), sortedVector.end());

    if (sortedVector.size() % 2 == 0)
        return (sortedVector[sortedVector.size() / 2 - 1] + sortedVector[sortedVector.size() / 2]) / 2.0;
    else
        return sortedVector[sortedVector.size() / 2];
}

// Apskaiciuojamas galutinis vidurkis su mediana
double GalutinisMed(const Studentas& duom) {
    double ndAverage = Mediana(duom.namudarbas);
    return 0.4 * ndAverage + 0.6 * duom.egzaminorez;
}