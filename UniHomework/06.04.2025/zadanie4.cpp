#include <iostream>

/* ZADANIE 4
   Napisz program w języku C++:
1) obliczający ile należy wypłacić pracownikowi pensji.
2) Program przyjmie stawkę za godzinę,
3) liczbę przepracowanych godzin
4) i wyświetli wynik mnożenia.
*/

int main(int argc, char* argv[])
{
   using namespace std;
   
   float przepracowaneGodziny,
         stawkaGodzinowa,
         pensja;
   
   // 2) Program przyjmie stawkę za godzinę,
   cout << "Podaj stawkę godzinową: ";
   cin >> stawkaGodzinowa;
   
   // 3) liczbę przepracowanych godzin
   cout << "Podaj przepracowane godziny: ";
   cin >> przepracowaneGodziny;
   
   // 1) obliczający ile należy wypłacić pracownikowi pensji.
   pensja = stawkaGodzinowa * przepracowaneGodziny;
   
   // Sprawdzanie błędów przy wpisywaniu
   if (przepracowaneGodziny < 0 or stawkaGodzinowa < 0) {
      cout << "Liczby nie mogą być ujemne!";
      return 1;
   }
   if (cin.fail()) {
      cout << "BŁĄD: Proszę podawać tylko liczby.";
      return 2;
   }

   // 4) i wyświetli wynik mnożenia.
   cout << "Pensja wynosi: " << pensja << "zł" << endl;
   
   return 0;
}