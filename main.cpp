//main.cpp
// g++ -o main main.cpp functions.cpp
// main.exe
#include "functions.h"
#include "main.h"


int main() {
    cout << "---------------------------------------- " << endl;
    int mode = NumberVerification("Manual input mode   [1]\nRead from file mode [2]\nInput: ", 1, 2);

    if (mode == 1) {
        manualmode();
    } 
    else if (mode == 2) {
        readingmode();
    }
    return 0;
}

