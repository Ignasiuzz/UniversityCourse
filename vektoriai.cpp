#include "includes.h"
#include "header.h"
#include "math.cpp"

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
    // Input file name
    ifstream inputFile("studentai100.txt");
    if (!inputFile) {
        cerr << "!ERROR! Unable to open the file." << endl;
        return;
    }

    cout << endl << "Sort by:" << endl << "Vardas   - 1," << endl << "Pavarde  - 2," << endl << "Vidurkis - 3," << endl << "Mediana  - 4." << endl << "Sorting: ";
    int sortby;
    cin >> sortby;

    string line;
    // Ignoruojama pirma eilute
    getline(inputFile, line);

    // Pradedamas skaiciuoti laikas
    auto start = high_resolution_clock::now();

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

    OutputBy(student, sortby);

    // Skaiciuojamas programos veikimo laikas
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Failo nuskaitymas uztruko " << duration.count() << " mikrosekundes," << endl;
    double microseconds = duration.count();
    double seconds = microseconds / 1000000;
    cout << "kas yra " << fixed << setprecision(6) << seconds << " sekundes.";
}

int main() {
    int mode;
    cout << "Manual input mode   - 1," << endl << "Read from file mode - 2. " << endl << "Input: ";
    cin >> mode;

    if (mode == 1)
        manualmode();
    else if (mode == 2)
        readingmode();
    else
        cout << "!ERROR! Invalid mode selected !" << endl;
    return 0;
}
