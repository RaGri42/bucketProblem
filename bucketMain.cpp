// _______________________________________________________________
// Copyright Oktober 2021, Spaichingen
// Autor:        Raphael Grimm <info@grimm-engineering.de>
// Compiler:     g++ 7.5.0 (Ubuntu 18.04)
// _______________________________________________________________
// Titel:        Bucket Exercise
// Firma:        Microtec, Bressanone/Brixen, Italy 
// Beschreibung: Algorithmus für die Loesung des 3-Eimer Problems
// _______________________________________________________________

#include <iostream>

// Bildschirmausgabe des Behaelterstandes
void printOut(int a, int b, int c) {

  std::cout << "a = "<< a << "  b = " << b << "  c = " << c << std::endl;

}


int main(int argc, char**argv) {
  // Startwerte
  // Fuellstaende
  int a = 8;
  int b = 0;
  int c = 0;

  // Kapazitaeten der Behaelter
  int ak = 8;
  int bk = 5;
  int ck = 3;

  // Hilfsvariable
  int rest = 0;
  
  // Ausgabe der Startwerte
  printOut(a, b, c);

  while (a - b) {

  if ((a > b) & (a > c)) {
    // a nach c schuetten
    if (((b == 0) & (c == 0)) || (b > c)) {
      rest = ck - c;
      c = c + rest;
      a = a - rest;
      printOut(a, b, c);
    }

    // c nach b schuetten
    else if (c > b) {
      rest = bk - b;
      if(rest >= c) {
        b = b + c;
        c = 0;
        printOut(a, b, c);
      }
    }
      
    else if (rest < c) {
        c = c - rest;
        b = b + c;
        printOut(a, b, c);
      }
    }

  else if ((a < b) & (a < c)) {
    if (b == c) {
    // c nach b schuetten
      rest = bk - b;
        if (rest >= c) {
          b = b + c;
          c = 0;
        }
        else if(rest < c){
          c = c - rest;
          b = b + rest;
        }
      printOut(a, b, c);
    }
  }

  else if ((a < b) & (a > c)) {
    // b nach a schuetten
    if (b > c) {
      rest = ak - a;
      if (rest >= b) {
        a = a + b;
        b = 0;
        }
       else if (rest < b) {
        b = b - rest;
        a = a + b;
        }
      printOut(a, b, c);
    }
  }
 }
 return 0;
}
