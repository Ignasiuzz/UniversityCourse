#ifndef STUDENTAS_H
#define STUDENTAS_H

struct Studentas {
    string Vardas, Pavarde;
    vector<int> namudarbas;
    int egzaminorez;
};

bool isString(const string& str_placeholder);
bool isInt(const string& str_placeholder);
void input(Studentas& duom);
double Vidurkis(const vector<int>& namudarbas);
double GalutinisVid(const Studentas& duom);
double Mediana(const vector<int>& namudarbas);
double GalutinisMed(const Studentas& duom);
void Output(const vector<Studentas>& student);
void OutputBy(const vector<Studentas>& student, int n);
void manualmode();
void readingmode();

#endif // STUDENTAS_H