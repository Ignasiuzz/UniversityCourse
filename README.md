# UniversityCourse
Objektinis programavimas

# Main files
main.cpp - pagrindinis failas  
header.h - aprasytos funkcijos ir strukturos  
includes.h - surasyti visi #include  
RandInt.hpp - skirta generuoti skaiciams  

# Extra files
1000_GeneratedStudents.txt  
10000_GeneratedStudents.txt  
100000_GeneratedStudents.txt  
1000000_GeneratedStudents.txt  
10000000_GeneratedStudents.txt  
## Speed analysis
### 1 tyrimas. Failu generavimas:

1000 studentu failo generacija uztruko 0.015287 sekundes.  
10.000 studentu failo generacija uztruko 0.084018 sekundes.  
100.000 studentu failo generacija uztruko 0.850757 sekundes.  
1.000.000 studentu failo generacija uztruko 6.90796 sekundes.  
10.000.000 studentu failo generacija uztruko 71.3354 sekundes.
### 2 tyrimas. Duomenų apdorijimas:

#### 1000 studentu  
Studentu failo skaitymas uztruko 0.017570 sekundes.  
Studentų rūšiavimas į dvi grupes uztruko 0.0026479 sekundes.  
Kietiaku isvedimas i faila uztruko 1.35245 sekundes.  
Nuskriaustuku isvedimas i faila uztruko 0.504344 sekundes.  
Visos programos veikimo laikas 1.877011 sekundes.

#### 10.000 studentu  
Studentu failo skaitymas uztruko 0.468288 sekundes.  
Studentų rūšiavimas į dvi grupes uztruko 0.243939 sekundes.  
Kietiaku isvedimas i faila uztruko 0.758017 sekundes.  
Nuskriaustuku isvedimas i faila uztruko 0.857197 sekundes.  
Visos programos veikimo laikas 2.32744 sekundes.

#### 100.000 studentu  
Studentu failo skaitymas uztruko 2.06379 sekundes.  
Studentų rūšiavimas į dvi grupes uztruko 2.22174 sekundes.  
Kietiaku isvedimas i faila uztruko 2.08051 sekundes.  
Nuskriaustuku isvedimas i faila uztruko 1.7924 sekundes.  
Visos programos veikimo laikas 8.15844 sekundes.

#### 1.000.000 studentu  
Studentu failo skaitymas uztruko 10.442 sekundes.  
Studentų rūšiavimas į dvi grupes uztruko 2.79593 sekundes.  
Kietiaku isvedimas i faila uztruko 16.3829 sekundes.  
Nuskriaustuku isvedimas i faila uztruko 11.9512 sekundes.  
Visos programos veikimo laikas 41.57203 sekundes.

#### 10.000.000 studentu  
Studentu failo skaitymas uztruko 83.9851 sekundes.  
Studentų rūšiavimas į dvi grupes uztruko 12.357 sekundes.  
Kietiaku isvedimas i faila uztruko 228.836 sekundes.  
Nuskriaustuku isvedimas i faila uztruko 168.7612 sekundes.  
Visos programos veikimo laikas 493.9393 sekundes.
## Speed Analysis with Vector container
### 1000 studentu

Failo nuskaitymas! File reading took 0.0064582 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 0.0015264 seconds.  
**1 strategija:**  
studentu grupes rusiavimas didejimo tvarka! Took 0.0015221 seconds.  
studentu grupes rusiavimas didejimo tvarka! Took 0.0009114 seconds.  
**2 strategija:** 
### 10000 studentu

Failo nuskaitymas! File reading took 0.308146 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 0.167959 seconds.  
**1 strategija:**  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.0170269 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.010611 seconds.  
**2 strategija:**  
### 100000 studentu

Failo nuskaitymas! File reading took 0.971385 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 1.10725 seconds.  
**1 strategija:**  
studentu grupes rusiavimas didejimo tvarka! Took 0.224068 seconds.  
studentu grupes rusiavimas didejimo tvarka! Took 0.158108 seconds.  
**2 strategija:**  
### 1000000 studentu

Failo nuskaitymas! File reading took 5.20445 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 1.70148 seconds.  
**1 strategija:**  
studentu grupes rusiavimas didejimo tvarka! Took 2.64111 seconds.  
studentu grupes rusiavimas didejimo tvarka! Took 1.89618 seconds.  
**1 strategija:**  

### 10000000 studentu
Failo nuskaitymas! File reading took 45.2525 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 7.14077 seconds.  
**1 strategija:**  
studentu grupes rusiavimas didejimo tvarka! Took 34.6841 seconds.  
studentu grupes rusiavimas didejimo tvarka! Took 34.6841 seconds.  
**2 strategija:**  
## Speed Analysis with List container
### 1000 studentu
  
Failo nuskaitymas! File reading took 0.0105633 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 0.0048674 seconds.  
**1 strategija:**  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.0005831 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.0003671 seconds.  
**2 strategija:**
### 10000 studentu

Failo nuskaitymas! File reading took 0.108236 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 0.0484067 seconds.  
**1 strategija:**  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.0075475 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.0049174 seconds.  
**2 strategija:**
### 100000 studentu

Failo nuskaitymas! File reading took 1.03398 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 0.476621 seconds.  
**1 strategija:**  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.0983661 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.0693338 seconds.  
**2 strategija:**
### 1000000 studentu

Failo nuskaitymas! File reading took 10.8194 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 4.85575 seconds.  
**1 strategija:**  
1 studentu grupes rusiavimas didejimo tvarka! Took 1.31633 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.860636 seconds.  
**2 strategija:**  
### 10000000 studentu
Failo nuskaitymas! File reading took 165.273 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 52.4094 seconds.  
**1 strategija:**  
1 studentu grupes rusiavimas didejimo tvarka! Took 15.0429 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 13.1367 seconds.  
**2 strategija:**  
