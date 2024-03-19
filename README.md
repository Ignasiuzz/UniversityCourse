# UniversityCourse
Objektinis programavimas  
Pirmoji Užduotis  
Ignas V
# Releases
**v.pradinė** - pati paprasčiausia programa, kuri gali skaičiuoti galutinį pažymį naudojant paprastą vidurkį arba medianą.  
**V0.1** - šioje versijoje yra du failai main.cpp ir vektoriai.cpp. Pirmas failas main.cpp veikia tik su C masyvais, antrasis vektoriai.cpp veikia tik su vector masyvais.  
**v0.2** - pridėta funkcija, kad duomenis būtų galima ne tik įvesti, bet ir nuskaityti iš failo.  
**V0.3** - atliktas refactoringas, pridėtas klaidų gaudymas.  
**v0.4** - pridėta galimybė generuoti studentus bei juos atskirti į dvi grupes.
**v1.0** - Finalinė programa. Programa realizuota su std::vector, std::list, std::deque. Testuotos trys studentų dalijimo į dvi grupes strategijos. Aprašyta programa.

# Main files
MainVector.cpp - Programa su Vector konteineriais  
VectorHeader.h - aprasytos funkcijos ir strukturos  
VectorIncludes.h - surasyti visi #include  

MainList.cpp - Programa su List konteineriais   
ListHeader.h - aprasytos funkcijos ir strukturos  
ListIncludes.h - surasyti visi #include  

MainDeque.cpp - Programa su Deque konteineriais   
DequeHeader.h - aprasytos funkcijos ir strukturos  
DequeIncludes.h - surasyti visi #include  

RandInt.hpp - skirta generuoti skaiciams  

# Extra files
1000_GeneratedStudents.txt  
10000_GeneratedStudents.txt  
100000_GeneratedStudents.txt  
1000000_GeneratedStudents.txt  
# Speed analysis
## 1 tyrimas. Failu generavimas [v0.4]:

1000 studentu failo generacija uztruko 0.015287 sekundes.  
10.000 studentu failo generacija uztruko 0.084018 sekundes.  
100.000 studentu failo generacija uztruko 0.850757 sekundes.  
1.000.000 studentu failo generacija uztruko 6.90796 sekundes.  
10.000.000 studentu failo generacija uztruko 71.3354 sekundes.
## 2 tyrimas. Duomenų apdorijimas [v0.4]:

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
## Testing Computer Hardware
CPU Ryzen 5 5600x  
RAM 32gb ddr4 3600mhz  
SSD Samsung 980 500gb 3500MB/s read, 3000MB/s read,


## Speed Analysis with Vector container (average) [v1.0]
### 1000 studentu

Failo nuskaitymas! File reading took 0.0030433 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two groups took 0.0003453 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.0012568 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.0007193 seconds.  
### 10000 studentu

Failo nuskaitymas! File reading took 0.0202934 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two groups took 0.003805 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.0192138 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.0110012 seconds.   
### 100000 studentu

Failo nuskaitymas! File reading took 0.191158 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two groups took 0.0308409 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.215776 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.154521 seconds.    
### 1000000 studentu

Failo nuskaitymas! File reading took 1.92851 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two groups took 0.304202 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 2.63818 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 1.91011 seconds.    

### 10000000 studentu
Failo nuskaitymas! File reading took 18.5539 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two groups took 2.96467 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 33.9316 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 22.6811 seconds.    
## Speed Analysis with List container (average) [v1.0]
### 1000 studentu
  
Failo nuskaitymas! File reading took 0.0029562 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two groups took 0.0013328 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.0006167 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.0004432 seconds.  
### 10000 studentu

Failo nuskaitymas! File reading took 0.0257348 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two groups took 0.0113529 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.0081756 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.0052752 seconds.  
### 100000 studentu

Failo nuskaitymas! File reading took 0.257668 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two groups took 0.121524 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.0924775 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.0684087 seconds.  
### 1000000 studentu

Failo nuskaitymas! File reading took 2.60287 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two groups took 1.28934 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 1.22637 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.827219 seconds.    
### 10000000 studentu
Failo nuskaitymas! File reading took 26.9321 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two groups took 13.3564 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 14.6688 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 9.74194 seconds.   
## Speed Analysis with Deque container (average) [v1.0]
### 1000 studentu
  
Failo nuskaitymas! File reading took 0.0020896 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two groups took 0.0008367 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.0015102 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.0008823 seconds.    
### 10000 studentu

Failo nuskaitymas! File reading took 0.0185253 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two groups took 0.0088459 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.0201471 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.0134492 seconds.    
### 100000 studentu

Failo nuskaitymas! File reading took 0.183295 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two groups took 0.0920748 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 0.256233 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 0.184438 seconds.    
### 1000000 studentu

Failo nuskaitymas! File reading took 1.80942 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two groups took 1.14468 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 3.04318 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 2.21802 seconds.      
### 10000000 studentu
Failo nuskaitymas! File reading took 18.2086 seconds.  
Studentu skirstymas i dvi grupes! Student sorting to two groups took 8.94321 seconds.  
1 studentu grupes rusiavimas didejimo tvarka! Took 40.0676 seconds.  
2 studentu grupes rusiavimas didejimo tvarka! Took 27.8034 seconds.  
## Konteineriu testavimo apibendrinimas
Atlikus konteineriu testasvima galime pastebėti, kad Vector ir Deque konteineriai yra labai panašūs savo veikimo greičiu bei savybėmis. List konteinerio informacijos nuskaitymas užtrunka ilgiau tačiau studentų dalijimas į dvi grupes bei rušiavimas yra daug greitesnis.
## Strategijų 1-3 analizė (average) [v1.0]
1 strategija: Bendro studentai konteinerio skaidymas į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų".  
2 strategija: Bendro studentų konteinerioskaidymas panaudojant tik vieną naują konteinerį: "vargšiukai". Tokiu būdu, jei studentas yra vargšiukas, jį turime įkelti į naująjį "vargšiukų" konteinerį ir ištrinti iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje liks vien tik kietiakai.  
3 strategija: Bendro studentų konteinerioskaidymas panaudojant greičiausiai veikianti 1 arba 2 strategiją įtraukiant į ją "efektyvius" darbo su konteineriais metodus.
### 1000 studentu
Vector  
1 Student sorting to two groups took 0.0003617 seconds.  
2 Student sorting to two groups took 0.0141142 seconds.  
3 Student sorting to two groups took 0.00033 seconds.  
List  
1 Student sorting to two vectors took 0.0013872 seconds.  
2 Student sorting to two groups took 0.0003498 seconds.   
3 Student sorting to two groups took 0.0004426 seconds.  
Deque  
1 Student sorting to two groups took 0.000958 seconds.  
2 Student sorting to two groups took 0.0080031 seconds.  
3 Student sorting to two groups took 0.0009854 seconds.
### 10000 studentu
Vector    
1 Student sorting to two groups took 0.0031811 seconds.  
2 Student sorting to two groups took 1.37601 seconds.  
3 Student sorting to two groups took 0.0039675 seconds.  
List  
1 Student sorting to two vectors took 0.0117402 seconds.  
2 Student sorting to two groups took 0.0028993 seconds.  
3 Student sorting to two groups took 0.0037563 seconds.  
Deque  
1 Student sorting to two groups took 0.0107672 seconds.  
2 Student sorting to two groups took 0.715232 seconds.  
3 Student sorting to two groups took 0.0079771 seconds.
### 100000 studentu
Vector    
1 Student sorting to two groups took 0.0285277 seconds.  
2 Student sorting to two groups did not finish [DNF]  
3 Student sorting to two groups took 0.024283 seconds.  
List  
1 Student sorting to two vectors took 0.116075 seconds.  
2 Student sorting to two groups took 0.0293661 seconds.  
3 Student sorting to two groups took 0.033782 seconds.  
Deque  
1 Student sorting to two groups took 0.0899883 seconds.  
2 Student sorting to two groups did not finish [DNF]  
3 Student sorting to two groups took 0.0820453 seconds.  
### 1000000 studentu
Vector  
1 Student sorting to two groups took 0.281021 seconds.  
2 Student sorting to two groups did not finish [DNF]  
3 Student sorting to two groups took 0.246047 seconds.  
List  
1 Student sorting to two vectors took 1.16253 seconds.  
2 Student sorting to two groups took 0.278465 seconds.  
3 Student sorting to two groups took 0.333081 seconds.  
Deque  
1 Student sorting to two groups took 0.886573 seconds.  
2 Student sorting to two groups did not finish [DNF]  
3 Student sorting to two groups took 0.869048 seconds.  

### 10000000 studentu
Vector  
1 Student sorting to two groups took 2.85402 seconds.  
2 Student sorting to two groups did not finish [DNF]   
2 Student sorting to two groups took 2.26505 seconds.  
List  
1 Student sorting to two vectors took 12.7083 seconds.  
2 Student sorting to two groups took 2.48508 seconds.  
3 Student sorting to two groups took 3.28574 seconds.  
Deque  
1 Student sorting to two groups took 11.8126 seconds.  
2 Student sorting to two groups did not finish [DNF]  
3 Student sorting to two groups took 9.99469 seconds.  
## Dalijimo strategijų testavimo apibendrinimas
Galime pastebėti, kad 2 dalijimo strategija veikė labai lėtai su Vector ir Deque konteineriais, tačiau programoje su List konteineriu ši strategija buvo optimaliausia ir greičiausia.
