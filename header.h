//header.h
#ifndef HEADER_H // redefinition apsauga
#define HEADER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

struct Studentas {
    string Vardas, Pavarde;
    vector<int> namudarbas;
    int egzaminorez;
};

#endif // HEADER_H