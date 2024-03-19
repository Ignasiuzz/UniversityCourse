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
## Speed Analysis with Vector container (average)
### 1000 studentu

Failo nuskaitymas! File reading took 0.0030433 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 0.0003453 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.0012568 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.0007193 seconds.  
### 10000 studentu

Failo nuskaitymas! File reading took 0.0202934 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 0.003805 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.0192138 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.0110012 seconds.   
### 100000 studentu

Failo nuskaitymas! File reading took 0.191158 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 0.0308409 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.215776 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.154521 seconds.    
### 1000000 studentu

Failo nuskaitymas! File reading took 1.92851 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 0.304202 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 2.63818 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 1.91011 seconds.    

### 10000000 studentu
Failo nuskaitymas! File reading took 18.5539 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 2.96467 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 33.9316 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 22.6811 seconds.    
## Speed Analysis with List container (average)
### 1000 studentu
  
Failo nuskaitymas! File reading took 0.0029562 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 0.0013328 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.0006167 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.0004432 seconds.  
### 10000 studentu

Failo nuskaitymas! File reading took 0.0257348 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 0.0113529 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.0081756 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.0052752 seconds.  
### 100000 studentu

Failo nuskaitymas! File reading took 0.257668 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 0.121524 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.0924775 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.0684087 seconds.  
### 1000000 studentu

Failo nuskaitymas! File reading took 2.60287 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 1.28934 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 1.22637 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.827219 seconds.    
### 10000000 studentu
Failo nuskaitymas! File reading took 26.9321 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 13.3564 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 14.6688 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 9.74194 seconds.   
## Speed Analysis with Deque container (average)
### 1000 studentu
  
Failo nuskaitymas! File reading took 0.0020896 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 0.0008367 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.0015102 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.0008823 seconds.    
### 10000 studentu

Failo nuskaitymas! File reading took 0.0185253 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 0.0088459 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.0201471 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.0134492 seconds.    
### 100000 studentu

Failo nuskaitymas! File reading took 0.183295 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 0.0920748 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.256233 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.184438 seconds.    
### 1000000 studentu

Failo nuskaitymas! File reading took 1.80942 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 1.14468 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 3.04318 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 2.21802 seconds.      
### 10000000 studentu
Failo nuskaitymas! File reading took 18.2086 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two vectors took 8.94321 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 40.0676 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 27.8034 seconds.  
