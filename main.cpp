#include <iomanip>
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

struct duom {
    string vardas;
    string pavarde;
    int nd;
    int egz;
};

int main() {
    duom a[500];
    int n, m;

    cout << "Iveskite mokiniu skaiciu: ";
    cin >> n;
    while (cin.fail()) { // tikrinama ar buvo ivestas skaicius, jei ne, prasoma ivesti vel
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Iveskite tinkama skaiciu!!!: ";
        cin >> n;
    }

    cout << "Iveskite namu darbu skaiciu: ";
    cin >> m;
    while (cin.fail()) { // tikrinama ar buvo ivestas skaicius, jei ne, prasoma ivesti vel
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Iveskite tinkama skaiciu!!!: ";
        cin >> m;
    }

    for (int i = 0; i < n; i++) { // informacijos ivedimas
        cout << "Iveskite mokinio varda: ";
        cin >> a[i].vardas;
        cout << "Iveskite mokinio pavarde: ";
        cin >> a[i].pavarde;
        for (int j = 0; j < m; j++) {
            cout << "Iveskite mokinio namu darbu rezultata: ";
            cin >> a[i].nd;
        }
        cout << "Iveskite mokinio egzamino rezultata: ";
        cin >> a[i].egz;
    }

    return 0;
}
