//vektoriai.cpp
#include "includes.h"
#include "header.h"
#include "FileInput.cpp"
#include "ManualInput.cpp"
#include "Verification.cpp"

int main() {

    int mode = NumberVerification("Manual input mode   - 1,\nRead from file mode - 2.\nInput: ", 1, 2);

    if (mode == 1) {
        manualmode();
    } else {
        readingmode();
    }

    return 0;
}
