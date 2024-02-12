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
    double vid; //vidurkis
    double med; //vidurkis naudojant mediana
};

void ivedimas ( int n, int m, duomenys a[]) {
    for (int i = 0; i < n; i++) { // informacijos ivedimas
        cout << "Iveskite mokinio varda: ";
        cin >> a[i].vardas;
        cout << "Iveskite mokinio pavarde: ";
        cin >> a[i].pavarde;
        for (int j = 0; j < m; j++) {
            cout << "Iveskite mokinio namu darbu rezultata: ";
            cin >> a[i].nd[j];

            while (a[i].nd[j] < 0 || a[i].nd[j] > 10) { //tikrinama ar buvo ivestas skaicius 10-baleje sistemoje
                cout << "!ERROR! Iveskite namu darbu rezultata 10-baleje sistemoje: ";
                cin >> a[i].nd[j];
            }
        }
        cout << "Iveskite mokinio egzamino rezultata: ";
        cin >> a[i].egz;

        while (a[i].egz < 0 || a[i].egz > 10) { //tikrinama ar buvo ivestas skaicius 10-baleje sistemoje
            cout << "!ERROR! Iveskite egzamino rezultata 10-baleje sistemoje: ";
            cin >> a[i].egz;
        }
    }
}

void vidurkis ( int n, int m, duomenys a[]) {
    for (int i = 0; i < n; i++) {
        double sum=0.0;
        for (int j = 0; j < m; j++) {
            sum += a[i].nd[j];
        }
        a[i].vid = 0.4*(sum/m) + 0.6*a[i].egz;
    }
}

void mediana ( int n, int m, duomenys a[]) {
    for (int i = 0; i < n; i++) { //vidurkis naudojant mediana
        int x = m/2;
        a[i].med==0.0;
        for (int j = 0; j < m - 1; j++) {
            for (int k = 0; k < m - j - 1; k++) {
                if (a[i].nd[k] > a[i].nd[k + 1]) {
                    int temp = a[i].nd[k];
                    a[i].nd[k] = a[i].nd[k + 1];
                    a[i].nd[k + 1] = temp;
                }
            }
        }
        if (m % 2 == 0)
        a[i].med = 0.4*((a[i].nd[x]+a[i].nd[x-1])/2) + 0.6*a[i].egz;
        else
        a[i].med = 0.4*a[i].nd[x] + 0.6*a[i].egz;
    }  
}

void isvedimas ( int n, duomenys a[]) {
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"Pavarde        Vardas         Galutinis (Vid.) / Galutinis (Med.)"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    for(int i = 0; i < n; i++){
        cout<<left<<setw(15)<<a[i].pavarde<<setw(15)<<a[i].vardas<<setw(19)<<setprecision(2)<<fixed<<a[i].vid<<setprecision(2)<<fixed<<a[i].med<<endl;
    }
}

int main() {
    duomenys a[100];
    int n, m;

    cout << "Iveskite mokiniu skaiciu: ";
    cin >> n;
    while (cin.fail()) { /* tikrinama ar buvo ivestas skaicius, jei ne, prasoma ivesti vel */
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "!ERROR! Iveskite skaiciu: ";
        cin >> n;
    }
    cout << "Iveskite namu darbu skaiciu: ";
    cin >> m;
    while (cin.fail()) { /* tikrinama ar buvo ivestas skaicius, jei ne, prasoma ivesti vel */
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "!ERROR! Iveskite skaiciu: ";
        cin >> m;
    }

    ivedimas (n, m, a);
    vidurkis (n, m, a);
    mediana (n, m, a);
    isvedimas (n, a);

    return 0;
}
