#include <iomanip>
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

struct duomenys { //duomenu struktura
    string vardas;
    string pavarde;
    int ndkiekis;
    int nd[100];
    int egz;
    double vid; //vidurkis
    double med; //vidurkis naudojant mediana
};

void ivestis1 ( int& n, duomenys a[]) {
    cout << "Iveskite mokiniu skaiciu: ";
    cin >> n;
    while (cin.fail()) { /* tikrinama ar buvo ivestas skaicius, jei ne, prasoma ivesti vel */
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "!ERROR! Iveskite skaiciu: ";
        cin >> n;
    }
    int m;
    cout << "Iveskite namu darbu skaiciu: ";
    cin >> m;
    while (cin.fail()) { /* tikrinama ar buvo ivestas skaicius, jei ne, prasoma ivesti vel */
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "!ERROR! Iveskite skaiciu: ";
        cin >> m;
    }

    for (int i = 0; i < n; i++) {
        a[i].ndkiekis = n;
    }

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

void ivestis2 ( int& n, duomenys a[]) {
    char loop, loop2;
    n = 0;
    do {
        a[n].ndkiekis=0;
        cout << "Ar norite ivesti naujo mokinio informacija (y/n) ";
        cin >> loop;

            if (loop == 'y') {
                cout << "Iveskite mokinio varda: ";
                cin >> a[n].vardas;
                cout << "Iveskite mokinio pavarde: ";
                cin >> a[n].pavarde;

                int j = 0;
                do {
                    cout << "Ar norite ivesti pazymi (y/n) ";
                    cin >> loop2;

                    if (loop2 == 'y') {
                        cout << "Iveskite mokinio namu darbu rezultata: ";
                        cin >> a[n].nd[j];

                        while (a[n].nd[j] < 0 || a[n].nd[j] > 10) { //tikrinama ar buvo ivestas skaicius 10-baleje sistemoje
                            cout << "!ERROR! Iveskite namu darbu rezultata 10-baleje sistemoje: ";
                            cin >> a[n].nd[j];
                        }
                        j++;
                    }

                } while (loop2 == 'y');

                a[n].ndkiekis = j;

                cout << "Iveskite mokinio egzamino rezultata: ";
                cin >> a[n].egz;

                while (a[n].egz < 0 || a[n].egz > 10) { /* Tikrinama ar buvo ivestas skaicius 10-baleje sistemoje */
                    cout << "!ERROR! Iveskite egzamino rezultata 10-baleje sistemoje: ";
                    cin >> a[n].egz;
                }

                n++;
            }
    }
    while (loop == 'y');
}

void vidurkis ( int n, duomenys a[]) {
    for (int i = 0; i < n; i++) {
        double sum=0.0;
        for (int j = 0; j < a[i].ndkiekis; j++) {
            sum += a[i].nd[j];
        }
        a[i].vid = 0.4*(sum/a[i].ndkiekis) + 0.6*a[i].egz;
    }
}

void mediana ( int n, duomenys a[]) {
    for (int i = 0; i < n; i++) { //vidurkis naudojant mediana
        int x = a[i].ndkiekis/2;
        a[i].med==0.0;
        for (int j = 0; j < a[i].ndkiekis - 1; j++) {
            for (int k = 0; k < a[i].ndkiekis - j - 1; k++) {
                if (a[i].nd[k] > a[i].nd[k + 1]) {
                    int temp = a[i].nd[k];
                    a[i].nd[k] = a[i].nd[k + 1];
                    a[i].nd[k + 1] = temp;
                }
            }
        }
        if (a[i].ndkiekis % 2 == 0)
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
    int n; //mokiniu skaicius
    int m; //namu darbu skaicius

    char mode;
    cout << "Ar zinomas mokiniu ir namu darbu skaicius (y/n) ";
    cin >> mode;

    if (mode == 'y' || mode == 'n') {
        if (mode == 'y') {
            ivestis1(n, a); /* Jeigu ZINOMAS mokiniu ir namu darbu skaicius */
        }
        else {
            ivestis2(n, a); /* Jeigu NEZINOMAS mokiniu ir namu darbu skaicius */
        }

        vidurkis(n, a); /* Skaiciuojamas vidurkis tradiciniu budu */
        mediana(n, a);  /* Skaiciuojamas vidurkis naudojant mediana */
        isvedimas(n, a);
    } 
    else {
        cout << "!ERROR! Bloga ivestis, bandykite dar karta" << endl;
        return 0;
    }

return 0;
}
