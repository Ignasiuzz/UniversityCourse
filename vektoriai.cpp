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

    // Use a do-while loop to allow the user to enter more grades or finish
    char choice;
    do {
        cout << "Iveskite studento namu darbu kieki (n): ";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Iveskite " << i + 1 << " namu darbo rezultata: ";
            int grade;
            cin >> grade;
            duom.namudarbas.push_back(grade);
        }

        cout << "Ar norite ivesti dar pazymiu? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

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
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Pavarde        Vardas         Galutinis (Vid.) / Galutinis (Med.)" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    for (const auto& duom : student) {
        cout << left<<setw(15) << duom.Pavarde << setw(15) << duom.Vardas << setw(15)<<fixed<<setprecision(2) << GalutinisVid(duom) << setw(19)<<fixed<<setprecision(2) << GalutinisMed(duom) << endl;
    }
    cout << "-----------------------------------------------------------------" << endl;
}

int main() {
    vector<Studentas> student;

    // Tikrinama ar is anksto zinomas studentu skaicius
    char mode;
    cout << "Ar zinomas studentu skaicius (y/n): ";
    cin >> mode;

    if (mode == 'y' || mode == 'n') {
        // Jeigu ZINOMAS studentu ir namu darbu skaicius
        if (mode == 'y') {
            int m;
            cout << "Iveskite studentu skaiciu: "; 
            cin >> m;

            vector<Studentas> student(m);

            for (int i = 0; i < m; i++) {
                input(student[i]);
            }

            output(student);
            return 0;
        }
        // Jeigu NEZINOMAS studentu ir namu darbu skaicius
        else {
            char choice;

            do {
            Studentas duom;
            input(duom);
            student.push_back(duom);

            cout << "Ar norite ivesti kita studenta? (y/n): ";
            cin >> choice;
            } 
            while (choice == 'y');

            output(student);
            return 0;
        }
    } 
    else {
        cout << "!ERROR! Kazkas neveikia, paleiskite programa is naujo" << endl;
        return 0;
    }
    return 0;
}
