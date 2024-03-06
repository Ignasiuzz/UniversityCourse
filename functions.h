//functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "header.h"

void readingmode();
void manualmode();
void input1(Studentas& duom);
void input2(Studentas& duom);
void input3(Studentas& duom, int n);
void OutputBy(const vector<Studentas>& student);
double Vidurkis(const vector<int>& namudarbas);
double GalutinisVid(const Studentas& duom);
double Mediana(const vector<int>& namudarbas);
double GalutinisMed(const Studentas& duom);
int NumberVerification(const string& prompt, int minValue, int maxValue);
int NumberVerification(const string& prompt, int minValue);
int YesNoVerification(const string& prompt);

#endif // FUNCTIONS_H
