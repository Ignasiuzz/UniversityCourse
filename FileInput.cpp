// FileInput.cpp
#include "math.cpp"
#include "includes.h"
#include "Verification.cpp"

void readingmode(){
    vector<Studentas> student;
    ifstream inputFile;
    try {
        inputFile.open("studentai100.txt");

        if (!inputFile) {
            throw invalid_argument("Neimanoma atidaryti failo.");
        }
    }
    catch (const invalid_argument& e) {
        cerr << "!ERROR! " << e.what() << endl;
        return;
    }

    // Pradedamas skaiciuoti laikas
    auto start = high_resolution_clock::now();

    string line;
    getline(inputFile, line);

    // SKaitoma ir apdorojama visa eilute
    while (getline(inputFile, line)) {
        Studentas duom;

        // Sukurtas "stringstream", kad galetume apdoroti kiekviena eilute
        istringstream get(line);

        get >> duom.Vardas >> duom.Pavarde;
        int grade;
        // Nuskaitomi visi skaiciai iki eilutes galo
        while (get >> grade) {
            duom.namudarbas.push_back(grade);
        }
        // Priskiriamas egzamino rezultatas yra paskutinis is nuskaitytu skaicius
        duom.egzaminorez = duom.namudarbas.back();
        duom.namudarbas.pop_back();

        student.push_back(duom);
    }
    inputFile.close();

    // Stabdomas skaiciuojamas laikas
    auto stop = high_resolution_clock::now();

    // Input verification
    int placeholder = NumberVerification("Sort by:\nVardas   - 1,\nPavarde  - 2,\nVidurkis - 3,\nMediana  - 4.\nSorting: ", 1, 4);
    OutputBy(student, placeholder);

    // Skaiciuojamas programos veikimo laikas
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Failo nuskaitymas uztruko " << duration.count() << " mikrosekundes," << endl;
    double microseconds = duration.count();
    double seconds = microseconds / 1000000;
    cout << "kas yra " << fixed << setprecision(6) << seconds << " sekundes.";
}

// Output by selected sorting
void OutputBy(const vector<Studentas>& student, int n) {
    vector<Studentas> sortedStudent = student;

    if ( n == 1 ){
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Vardas         Pavarde        Galutinis (Vid.) / Galutinis (Med.)" << endl;
        cout << "-----------------------------------------------------------------" << endl;

        sort(sortedStudent.begin(), sortedStudent.end(), [](const Studentas& a, const Studentas& b) {
            return stoi(a.Vardas.substr(6)) < stoi(b.Vardas.substr(6));
        });

        for (const auto& duom : sortedStudent) {
            cout << left << setw(15) << duom.Vardas << setw(15) << duom.Pavarde << setw(15)<<fixed<<setprecision(2) << GalutinisVid(duom) << setw(19)<<fixed<<setprecision(2) << GalutinisMed(duom) << endl;
        }
        cout << "-----------------------------------------------------------------" << endl;
    }

    else if ( n == 2 ){
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Pavarde         Vardas        Galutinis (Vid.) / Galutinis (Med.)" << endl;
        cout << "-----------------------------------------------------------------" << endl;

        sort(sortedStudent.begin(), sortedStudent.end(), [](const Studentas& a, const Studentas& b) {
            return stoi(a.Pavarde.substr(7)) < stoi(b.Pavarde.substr(7));
        });

        for (const auto& duom : sortedStudent) {
            cout << left << setw(15) << duom.Pavarde << setw(15) << duom.Vardas << setw(15)<<fixed<<setprecision(2) << GalutinisVid(duom) << setw(19)<<fixed<<setprecision(2) << GalutinisMed(duom) << endl;
        }
        cout << "-----------------------------------------------------------------" << endl;
    }

    else if ( n == 3 ){
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Galutinis (Vid.) Pavarde        Vardas         Galutinis (Med.)" << endl;
        cout << "-----------------------------------------------------------------" << endl;

            sort(sortedStudent.begin(), sortedStudent.end(), [](const Studentas& a, const Studentas& b) {
                return GalutinisVid(a) < GalutinisVid(b);
            });

        for (const auto& duom : sortedStudent) {
            cout << left << setw(17) << fixed << setprecision(2) << GalutinisVid(duom) << setw(15) << duom.Pavarde << setw(15) << duom.Vardas << setw(19) << fixed << setprecision(2) << GalutinisMed(duom) << endl;
        }
        cout << "-----------------------------------------------------------------" << endl;
    }

    else if ( n == 4 ){
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Galutinis (Med.) Pavarde        Vardas         Galutinis (vid.)" << endl;
        cout << "-----------------------------------------------------------------" << endl;

            sort(sortedStudent.begin(), sortedStudent.end(), [](const Studentas& a, const Studentas& b) {
                return GalutinisMed(a) < GalutinisMed(b);
            });

        for (const auto& duom : sortedStudent) {
            cout << left << setw(17) << fixed << setprecision(2) << GalutinisMed(duom) << setw(15) << duom.Pavarde << setw(15) << duom.Vardas << setw(19) << fixed << setprecision(2) << GalutinisMed(duom) << endl;
        }
        cout << "-----------------------------------------------------------------" << endl;
    }
}