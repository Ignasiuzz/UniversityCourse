#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

struct Studentas {
    string Vardas, Pavarde;
    vector<int> namudarbas;
    int egzaminorez;
};

void input(Studentas& duom) {
    cout << "Iveskite studento varda: ";
    cin >> duom.Vardas;
    cout << "Iveskite studento pavarde: ";
    cin >> duom.Pavarde;
    cout << "Iveskite studento namu darbu kieki (n): ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Iveskite " << i + 1 << " namu darbo rezultata: ";
        int grade;
        cin >> grade;
        duom.namudarbas.push_back(grade);
    }
    sort(duom.namudarbas.begin(), duom.namudarbas.end());

    cout << "Iveskite studento egzamino rezultata: ";
    cin >> duom.egzaminorez;
}

double Vidurkis(const vector<int>& namudarbas) {
    double sum = 0;
    for (int i = 0; i < namudarbas.size(); i++) {
        sum += namudarbas[i];
    }
    return sum / namudarbas.size();
}

double GalutinisVid(const Studentas& duom) {
    double ndAverage = Vidurkis(duom.namudarbas);
    return 0.4 * ndAverage + 0.6 * duom.egzaminorez;
}

double Mediana(const vector<int>& namudarbas) {
    vector<int> sortedVector = namudarbas;
    sort(sortedVector.begin(), sortedVector.end());

    if (sortedVector.size() % 2 == 0) {
        return (sortedVector[sortedVector.size() / 2 - 1] + sortedVector[sortedVector.size() / 2]) / 2.0;
    } 
    else {
        return sortedVector[sortedVector.size() / 2];
    }
}

double GalutinisMed(const Studentas& duom) {
    double ndAverage = Mediana(duom.namudarbas);
    return 0.4 * ndAverage + 0.6 * duom.egzaminorez;
}

void output(const vector<Studentas>& student) {
    cout << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.)" << endl;
    cout << "-------------------------------------------------------" << endl;
    for (const auto& duom : student) {
        cout << duom.Pavarde << setw(15) << duom.Vardas << setw(15) << fixed << setprecision(2) << GalutinisVid(duom) << setw(6) << fixed << setprecision(2) << GalutinisMed(duom) << endl;
    }
}

int main() {
    vector<Studentas> student;

    char choice;
    do {
        Studentas duom;
        input(duom);
        student.push_back(duom);

        cout << "Ar norite ivesti kita studenta? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    output(student);

    return 0;
}
