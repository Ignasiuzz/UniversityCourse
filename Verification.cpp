// Verification.cpp
#ifndef VERIFICATION_CPP // redefinition apsauga
#define VERIFICATION_CPP

#include "math.cpp"
#include "includes.h"

int NumberVerification(const string& prompt, int minValue, int maxValue) {
    int value;
    string input;

    while (true) {
        cout << prompt;
        try {
            cin >> input;
            // Paverciame string i integeri
            value = stoi(input);

            // Paziurime ar convertuotas int yra mazesnis uz inputo dydi
            if (value < input.size()) {
                throw invalid_argument("");
            }

            // Patikriname ar skaicius yra tarp nurodytu dvieju skaiciu
            if (value < minValue || value > maxValue) {
                throw out_of_range("Ivestis uz diapazono ribu. Prasome ivesti skaiciu nuo " + to_string(minValue) + " iki " + to_string(maxValue) + ".");
            }
            
            return value;
        } catch (const invalid_argument& e) {
            cerr << "!Error! Prasome ivesti SVEIKAJI skaiciu." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Istrinama neteisinga ivestis
        } catch (const out_of_range& e) {
            cerr << "!Error! " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Istrinama neteisinga ivestis
        }
    }
}

int NumberVerification(const string& prompt, int minValue) {
    int value;
    string input;

    while (true) {
        cout << prompt;
        try {
            cin >> input;
            // Paverciame string i integeri
            value = stoi(input);
            
            // Paziurime ar convertuotas int yra mazesnis uz inputo dydi
            if (value < input.size()) {
                throw invalid_argument("");
            }
            
            // Patikriname ar skaicius yra didnesnis uz nurodyta skaiciu
            if (value < minValue) {
                throw out_of_range("Input is below the minimum allowed value. Please enter a number greater than or equal to " + to_string(minValue) + ".");
            }

            return value;
        } catch (const invalid_argument& e) {
            cerr << "!Error! Prasome ivesti SVEIKAJI skaiciu." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Istrinama neteisinga ivestis
        } catch (const out_of_range& e) {
            cerr << "!Error! " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Istrinama neteisinga ivestis
        }
    }
}

int YesNoVerification(const string& prompt) {
    char input;

    while (true) {
        cout << prompt;
        try {
            cin >> input;
            // Tikriname ar buvo ivesta tik 'y' arba tik 'n'
            if ( input == 'y' || input == 'n' )
                return input;
            else 
                throw runtime_error("Prasome ivesti 'y' arba 'n'.");
            
        }
        catch (const exception& e) {
            cerr << "!Error! " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Istrinama neteisinga ivestis
        }
    }
}

#endif // VERIFICATION_CPP