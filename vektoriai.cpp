#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

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

    srand(static_cast<unsigned int>(time(0)));

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

        for (int i = 0; i < n; i++) {
            cout << "Ar norite atsitiktinai generuoti namu darbo pazymi (y/n): ";
            cin >> choice;

            while (cin.fail() || (choice != 'y' && choice != 'n')) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "!ERROR! Iveskite 'y' arba 'n': ";
            cin >> choice;
            }

            if (choice == 'y'){
                int_placeholder = rand() % 10 + 1;
                cout << "Namu darbo pazymys: " << int_placeholder << "." << endl;
            }
            else {
            // Namu darbu rezultato input verification
            do {
                cout << "Iveskite " << i + 1 << " namu darbo rezultata: ";
                cin >> str_placeholder;
                        
                if (!isInt(str_placeholder)){
                    cout << "!ERROR! Prasome ivesti skaiciu nuo 1 iki 10 !" << endl;
                }
            } while (!isInt(str_placeholder));
            int_placeholder = stoi(str_placeholder);
            }
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
        cout << "Ar norite atsitiktinai generuoti ezgamino pazymius (y/n): ";
        cin >> choice;

        while (cin.fail() || (choice != 'y' && choice != 'n')) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "!ERROR! Iveskite 'y' arba 'n': ";
        cin >> choice;
        }

        if (choice == 'y'){
            int_placeholder = rand() % 10 + 1;
            cout << "Egzamino pazymys: " << int_placeholder << "." << endl;
        }
        else {
            cout << "Iveskite studento egzamino rezultata: ";
            cin >> str_placeholder;
                        
            if (!isInt(str_placeholder)){
                cout << "!ERROR! Prasome ivesti skaiciu nuo 1 iki 10 !" << endl;
            }
            int_placeholder = stoi(str_placeholder);
        }
    } while (!isInt(str_placeholder));
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

void OutputBy(const vector<Studentas>& student, int n) {
    if ( n == 1){
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Galutinis (Vid.) Pavarde        Vardas         Galutinis (Med.)" << endl;
        cout << "-----------------------------------------------------------------" << endl;

        vector<Studentas> sortedStudent = student;

            sort(sortedStudent.begin(), sortedStudent.end(), [](const Studentas& a, const Studentas& b) {
                return GalutinisVid(a) < GalutinisVid(b);
            });

        for (const auto& duom : sortedStudent) {
            cout << left << setw(17) << fixed << setprecision(2) << GalutinisVid(duom) << setw(15) << duom.Pavarde << setw(15) << duom.Vardas << setw(19) << fixed << setprecision(2) << GalutinisMed(duom) << endl;
        }
        cout << "-----------------------------------------------------------------" << endl;
    }

    else if ( n == 2 ){
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Galutinis (Med.) Pavarde        Vardas         Galutinis (vid.)" << endl;
        cout << "-----------------------------------------------------------------" << endl;

        vector<Studentas> sortedStudent = student;

            sort(sortedStudent.begin(), sortedStudent.end(), [](const Studentas& a, const Studentas& b) {
                return GalutinisMed(a) < GalutinisMed(b);
            });

        for (const auto& duom : sortedStudent) {
            cout << left << setw(17) << fixed << setprecision(2) << GalutinisMed(duom) << setw(15) << duom.Pavarde << setw(15) << duom.Vardas << setw(19) << fixed << setprecision(2) << GalutinisMed(duom) << endl;
        }
        cout << "-----------------------------------------------------------------" << endl;
    }
}

void manualmode(){
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
        }
    } 
    else {
        cout << "!ERROR! Kazkas neveikia, paleiskite programa is naujo" << endl;
    }
}

void readingmode(){
    vector<Studentas> student;

    ifstream inputFile("studentai50.txt");

    if (!inputFile) {
        cerr << "!ERROR! Unable to open the file." << endl;
        return;
    }

    string line;
    // Ignoruojama pirma eilute
    getline(inputFile, line);
    // Pradedamas skaiciuoti laikas
    auto start = high_resolution_clock::now();

    // SKaitoma ir apdorojama visa eilute
    while (getline(inputFile, line)) {
        Studentas duom;

        // Sukurtas "stringstream", kad galetume apdoroti kiekviena eilute
        istringstream iss(line);

        iss >> duom.Vardas >> duom.Pavarde;
        for (int i = 0; i < 15; ++i) {
            int grade;
            iss >> grade;
            duom.namudarbas.push_back(grade);
        }
        iss >> duom.egzaminorez;

        student.push_back(duom);
    }
    inputFile.close();

    OutputBy(student, 2);

    // Stabdomas skaiciuojamas laikas
    auto stop = high_resolution_clock::now();

    // Skaiciuojamas programos veikimo laikas
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Funkcija uztruko " << duration.count() << " mikrosekundes," << endl;
    double microseconds = duration.count();
    double seconds = microseconds / 1000000;
    cout << "kas yra " << fixed << setprecision(6) << seconds << " sekundes.";
}

int main() {
    int mode;
    cout << "Manual input mode - 1" << endl << "Reading mode - 2: " << endl << "Mode: ";
    cin >> mode;

    if (mode == 1)
        manualmode();
    else if (mode == 2)
        readingmode();
    else
        cout << "!ERROR! Invalid mode selected !" << endl;
    return 0;
}
