// ManualInput.cpp
#include "math.cpp"
#include "includes.h"
#include "Verification.cpp"

char string_temp;
int int_temp;

void manualmode(){
    vector<Studentas> student;
    cout << "---------------------------------------- " << endl;
    int_temp = NumberVerification("Zinomas mokiniu ir pazymiu skaicius   [1]\nNezinomas mokiniu ir pazymiu skaicius [2]\nGeneruoti mokinius ir pazymius        [3]\nInput: ", 1, 3);
    cout << "---------------------------------------- " << endl;
    
    if (int_temp == 1) {
        int m = NumberVerification("Iveskite studentu skaiciu: ", 1);
        vector<Studentas> student(m);

        for (int i = 0; i < m; i++) {
            input1(student[i]);
        }

        Output(student);
    }
    else if (int_temp == 2){
        do {
        Studentas duom;
        input2(duom);
        student.push_back(duom);

        string_temp = YesNoVerification("Ar norite ivesti kita studenta? (y/n): ");
        }
        while (string_temp == 'y');

        Output(student);
    }
    else if (int_temp == 3){
        int m = NumberVerification("Iveskite studentu skaiciu: ", 1);
        int n = NumberVerification("Iveskite studento namu darbu kieki (n): ", 1);
        srand(time(0));

        vector<Studentas> student(m);

        for (int i = 0; i < m; i++) {
            input3(student[i], n);
        }

        Output(student);
    } 
}

void input1(Studentas& duom) {
    cout << "Iveskite studento varda: ";
    cin >> duom.Vardas;

    cout << "Iveskite studento pavarde: ";
    cin >> duom.Pavarde;

    int_temp = NumberVerification("Iveskite studento namu darbu kieki (n): ", 1);
    for (int i = 0; i < int_temp; i++) {
        int int_temp = NumberVerification("Iveskite namu darbo rezultata: ", 1, 10);
        duom.namudarbas.push_back(int_temp);
    }
    
    int_temp = NumberVerification("Iveskite studento egzamino rezultata:", 1, 10);
    duom.egzaminorez = int_temp;
}

void input2(Studentas& duom) {
    cout << "Iveskite studento varda: ";
    cin >> duom.Vardas;

    cout << "Iveskite studento pavarde: ";
    cin >> duom.Pavarde;

    do {
        int_temp = NumberVerification("Iveskite studento namu darbu kieki (n): ", 1);
        for (int i = 0; i < int_temp; i++) {
            int int_temp = NumberVerification("Iveskite namu darbo rezultata: ", 1, 10);
            duom.namudarbas.push_back(int_temp);
        }

        string_temp = YesNoVerification("Ar norite ivesti dar pazymiu? (y/n): ");
        
    } while (string_temp == 'y');
    
    int_temp = NumberVerification("Iveskite studento egzamino rezultata:", 1, 10);
    duom.egzaminorez = int_temp;
}

void input3(Studentas& duom, int n) {
    vector<string> NameArray = { "Jonas", "Vytautas", "Antanas", "Tomas", "Juozas", "Petras", "Gediminas", "Danielius", "Oskaras", "Linas" };
    vector<string> SurnameArray = { "Kazlauskas", "Stankevicius", "Petrauskas", "Jankauskas", "Butkus", "Paulauskas", "Urbonas", "Navickas", "Rimkus", "Bagdonas" };

    duom.Vardas = NameArray[rand() % NameArray.size()];
    duom.Pavarde = SurnameArray[rand() % SurnameArray.size()];

    for (int i = 0; i < n; i++) {
        duom.namudarbas.push_back(rand() % 10);
    }

    duom.egzaminorez = rand() % 10;
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