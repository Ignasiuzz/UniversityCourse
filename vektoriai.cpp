//vektoriai.cpp
#include "includes.h"
#include "header.h"
#include "FileInput.cpp"
#include "ManualInput.cpp"

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
