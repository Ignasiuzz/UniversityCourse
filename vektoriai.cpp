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

bool isString(const string& str_placeholder){
    for (char c : str_placeholder) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

bool isInt(const string& str_placeholder){
    for (char c : str_placeholder){
        if (!isdigit(c)){
            return false;
        }

        int grade = stoi(str_placeholder);

        if (grade > 10 || grade < 0){
            return false;
        }
    }
    return true;
}

void input(Studentas& duom) {
    string str_placeholder;
    int int_placeholder;
    char choice;
    int n;

    // Vardo input verification
    do {
        cout << "Iveskite studento varda: ";
        cin >> str_placeholder;
                
        if (!isString(str_placeholder)){
            cout << "!ERROR! Studentu varduose negali buti skaiciu !" << endl;
        }
    } while (!isString(str_placeholder));
    duom.Vardas = str_placeholder;

    // Pavardes input verification
    do {
        cout << "Iveskite studento pavarde: ";
        cin >> str_placeholder;
                
        if (!isString(str_placeholder)){
            cout << "!ERROR! Studentu pavardese negali buti skaiciu !" << endl;
        }
    } while (!isString(str_placeholder));
    duom.Pavarde = str_placeholder;

    // Pazymiu loop
    do {
        // Namu darbu kiekio input verification
        do {
            cout << "Iveskite studento namu darbu kieki (n): ";
            cin >> str_placeholder;
                    
            if (!isInt(str_placeholder)){
                cout << "!ERROR! Prasome ivesti skaiciu nuo 1 iki 10 !" << endl;
            }
        } while (!isInt(str_placeholder));
        int_placeholder = stoi(str_placeholder);
        n = int_placeholder;

        // Namu darbu rezultato input verification
        for (int i = 0; i < n; i++) {
            do {
                cout << "Iveskite " << i + 1 << " namu darbo rezultata: ";
                cin >> str_placeholder;
                        
                if (!isInt(str_placeholder)){
                    cout << "!ERROR! Prasome ivesti skaiciu nuo 1 iki 10 !" << endl;
                }
            } while (!isInt(str_placeholder));
            int_placeholder = stoi(str_placeholder);
            duom.namudarbas.push_back(int_placeholder);
        }

        cout << "Ar norite ivesti dar pazymiu? (y/n): ";
        cin >> choice;
        // Tikrinama ar buvo ivesta y arba n
        while (cin.fail() || (choice != 'y' && choice != 'n')) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "!ERROR! Iveskite 'y' arba 'n': ";
        cin >> choice;
        }
        
    } while (choice == 'y' || choice == 'Y');


    do {
        cout << "Iveskite studento egzamino rezultata: ";
        cin >> str_placeholder;
                    
        if (!isInt(str_placeholder)){
            cout << "!ERROR! Prasome ivesti skaiciu nuo 1 iki 10 !" << endl;
        }
    } while (!isInt(str_placeholder));
    int_placeholder = stoi(str_placeholder);
    duom.egzaminorez = int_placeholder;
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

void Output(const vector<Studentas>& student) {
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
    // Tikrinama ar buvo ivesta y arba n
    while (cin.fail() || (mode != 'y' && mode != 'n')) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "!ERROR! Iveskite 'y' arba 'n': ";
    cin >> mode;
    }

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

            Output(student);
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

            // Tikrinama ar buvo ivesta y arba n
            while (cin.fail() || (choice != 'y' && choice != 'n')) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "!ERROR! Iveskite 'y' arba 'n': ";
            cin >> choice;
    }
            } 
            while (choice == 'y');

            Output(student);
            return 0;
        }
    } 
    else {
        cout << "!ERROR! Kazkas neveikia, paleiskite programa is naujo" << endl;
        return 0;
    }
    return 0;
}
