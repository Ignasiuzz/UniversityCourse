#ifndef VERIFICATION_CPP // redefinition apsauga
#define VERIFICATION_CPP
// Verification.cpp
#include "math.cpp"
#include "includes.h"

/* Tutorial */
// int NumberVerification("zinute", int minValue, int maxValue)

int NumberVerification(const string& prompt, int minValue, int maxValue) {
    int value;
    string input;

    while (true) {
        cout << prompt;
        try {
            cin >> input;
            size_t pos;
            value = stoi(input, &pos);

            if (pos < input.size()) {
                throw invalid_argument("");  // Jeigu ivestas ne sveikasis skaicius
            }

            if (value < minValue || value > maxValue) {
                throw out_of_range("Ivestis uz diapazono ribu. Prasome ivesti skaiciu nuo " + to_string(minValue) + " iki " + to_string(maxValue) + ".");
            }

            // If we reach here, the input is valid
            return value;
        } catch (const invalid_argument& e) {
            cerr << "Error: Prasome ivesti SVEIKAJI skaiciu." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Istrinama neteisinga ivestis
        } catch (const out_of_range& e) {
            cerr << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Istrinama neteisinga ivestis
        }
    }
}

#endif // VERIFICATION_CPP