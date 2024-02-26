//vektoriai.cpp
#include "includes.h"
#include "header.h"
#include "FileInput.cpp"
#include "ManualInput.cpp"
#include "Verification.cpp"

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
    try {
        int mode = NumberVerification("Manual input mode   - 1,\nRead from file mode - 2.\nInput: ", 1, 2);

        if (mode == 1) {
            manualmode();
        } else {
            readingmode();
        }

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1; // Return a non-zero value to indicate an error
    }

    return 0;
}
