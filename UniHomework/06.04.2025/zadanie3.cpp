#include <iostream>

/* ZADANIE 3:
   Napisz program w języku C++:
1) obliczający pole prostokąta
2) na podstawie podanych przez użytkownika wartości dwóch boków.
3) Jeśli figura jest kwadratem program dodatkowo informuje o tym użytkownika.
*/

int main(int argc, char* argv[])
{
   using namespace std;
   
   float bokA,
         bokB;
       
   // 2) na podstawie podanych przez użytkownika wartości dwóch boków
   cout << "Podaj długości boków A i B: ";
   cin >> bokA >> bokB;

   // Sprawdzanie błędów przy wpisywaniu
   if (bokA < 0 or bokB < 0) {
      cout << "Długości boków nie mogą być ujemne!";
      return 1;
   }
   if (cin.fail()) {
      cout << "BŁĄD: Proszę wpisywać tylko liczby";
      return 2;
   }
   
   // 1) obliczający pole prostokąta
   cout << "Pole tego prostokąta wynosi: " << bokA*bokB << endl;
   
   // 3) Jeśli figura jest kwadratem program dodatkowo informuje o tym użytkownika.
   if (bokA == bokB)
      cout << "Podany prostokąt jest dodatkowo kwadratem!" << endl;
   
   return 0;
}