#include <iomanip>
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

struct duomenys { //duomenu struktura
    string vardas;
    string pavarde;
    int nd[100];
    int egz;
    double vid;
};

int main() {
    duomenys a[100];
    int n, m;

    cout << "Iveskite mokiniu skaiciu: ";
    cin >> n;
    while (cin.fail()) { // tikrinama ar buvo ivestas skaicius, jei ne, prasoma ivesti vel
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "!ERROR! Iveskite skaiciu: ";
        cin >> n;
    }

    cout << "Iveskite namu darbu skaiciu: ";
    cin >> m;
    while (cin.fail()) { // tikrinama ar buvo ivestas skaicius, jei ne, prasoma ivesti vel
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "!ERROR! Iveskite skaiciu: ";
        cin >> m;
    }

    for (int i = 0; i < n; i++) { // informacijos ivedimas
        cout << "Iveskite mokinio varda: ";
        cin >> a[i].vardas;
        cout << "Iveskite mokinio pavarde: ";
        cin >> a[i].pavarde;
        for (int j = 0; j < m; j++) {
            cout << "Iveskite mokinio namu darbu rezultata: ";
            cin >> a[i].nd[j];

            while(a[i].nd[j] < 0 || a[i].nd[j] > 10){ //tikrinama ar buvo ivestas skaicius 10-baleje sistemoje
                cout << "!ERROR! Iveskite namu darbu rezultata 10-baleje sistemoje: ";
                cin >> a[i].nd[j];
            }
        }
        cout << "Iveskite mokinio egzamino rezultata: ";
        cin >> a[i].egz;

        while(a[i].egz < 0 || a[i].egz > 10){ //tikrinama ar buvo ivestas skaicius 10-baleje sistemoje
            cout << "!ERROR! Iveskite egzamino rezultata 10-baleje sistemoje: ";
            cin >> a[i].egz;
        }
    }

    for(int i = 0; i < n; i++) {
        double sum=0.0;
        for(int j = 0; j < m; j++) {
        sum += a[i].nd[j];
        }
        cout<<sum<<endl;
        a[i].vid = 0.4*(sum/m) + 0.6*a[i].egz;
    }

    cout<<"Pavarde        Vardas         Galutinis (Vid.)"<<endl;
    cout<<"----------------------------------------------"<<endl;
    for(int i = 0; i < n; i++){
        cout<<left<<setw(15)<<a[i].pavarde<<setw(15)<<a[i].vardas<<setw(15)<<setprecision(3)<<a[i].vid<<endl;
    }

    return 0;
}
