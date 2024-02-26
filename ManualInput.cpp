// ManualInput.cpp
#include "math.cpp"
#include "includes.h"
#include "Verification.cpp"

char str_placeholder;
int int_placeholder;

void manualmode(){
    vector<Studentas> student;

    int_placeholder = NumberVerification("Zinomas mokiniu ir pazymiu skaicius - 1,\nNezinomas mokiniu ir pazymiu skaicius - 2,\nGeneruoti mokinius ir pazymius - 3.", 1, 3);

    if (int_placeholder == 1) {
        int m = NumberVerification("Iveskite studentu skaiciu: ", 1);
        vector<Studentas> student(m);

        for (int i = 0; i < m; i++) {
            input1(student[i]);
        }

        Output(student);
    }
    else if (int_placeholder == 2){
        do {
        Studentas duom;
        input2(duom);
        student.push_back(duom);

        str_placeholder = YesNoVerification("Ar norite ivesti kita studenta? (y/n): ");
        }
        while (str_placeholder == 'y');

        Output(student);
    }
    else if (int_placeholder == 3){
        int m = NumberVerification("Iveskite studentu skaiciu: ", 1);
        vector<Studentas> student(m);

        for (int i = 0; i < m; i++) {
            input1(student[i]);
        }

        Output(student);
    } 
}

void input1(Studentas& duom) {
    cout << "Iveskite studento varda: ";
    cin >> duom.Vardas;

    cout << "Iveskite studento pavarde: ";
    cin >> duom.Pavarde;

    int_placeholder = NumberVerification("Iveskite studento namu darbu kieki (n): ", 1);
    for (int i = 0; i < int_placeholder; i++) {
        int int_placeholder = NumberVerification("Iveskite namu darbo rezultata: ", 1, 10);
        duom.namudarbas.push_back(int_placeholder);
    }
    
    int_placeholder = NumberVerification("Iveskite studento egzamino rezultata:", 1, 10);
    duom.egzaminorez = int_placeholder;
}

void input2(Studentas& duom) {
    cout << "Iveskite studento varda: ";
    cin >> duom.Vardas;

    cout << "Iveskite studento pavarde: ";
    cin >> duom.Pavarde;

    do {
        int_placeholder = NumberVerification("Iveskite studento namu darbu kieki (n): ", 1);
        for (int i = 0; i < int_placeholder; i++) {
            int int_placeholder = NumberVerification("Iveskite namu darbo rezultata: ", 1, 10);
            duom.namudarbas.push_back(int_placeholder);
        }

        str_placeholder = YesNoVerification("Ar norite ivesti dar pazymiu? (y/n): ");
        
    } while (str_placeholder == 'y');
    
    int_placeholder = NumberVerification("Iveskite studento egzamino rezultata:", 1, 10);
    duom.egzaminorez = int_placeholder;
}

void input3(Studentas& duom) {

    srand(static_cast<unsigned int>(time(0)));

    cout << "Iveskite studento varda: ";
    cin >> duom.Vardas;

    cout << "Iveskite studento pavarde: ";
    cin >> duom.Pavarde;

    do {
        int_placeholder = NumberVerification("Iveskite studento namu darbu kieki (n): ", 1);
        for (int i = 0; i < int_placeholder; i++) {
            int int_placeholder = NumberVerification("Iveskite namu darbo rezultata: ", 1, 10);
            duom.namudarbas.push_back(int_placeholder);
        }

        str_placeholder = YesNoVerification("Ar norite ivesti dar pazymiu? (y/n): ");
        
    } while (str_placeholder == 'y');
    
    int_placeholder = NumberVerification("Iveskite studento egzamino rezultata:", 1, 10);
    duom.egzaminorez = int_placeholder;
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