#include <iostream>

using namespace std;

/*
1) Napisz program w C++, który ma proste menu. Użytkownik wybiera opcję z menu:
a) program pobiera dwie liczby całkowite i oblicza ich sumę, wyświetla wynik na ekran.
b) program wyświetla tekst z użyciem podanej danej np.: jeśli użytkownik napisał literę C, wyświetla „Napisałeś literę C”
c) pobiera od użytkownika liczbę i wyświetla większą oraz mniejszą o jeden.
*/

void suma();
void echo();
void neighbour();

int main(int argc, char* argv[])
{
   int option;
   
   enum options {
      ERROR = 0,
      SUMA = 1,
      ECHO = 2,
      NEIGHBOUR = 3,
      EXIT = 4,
      CONTINUE = 5,
   };
   option = CONTINUE;
   
   // 1) Napisz program w C++, który ma proste menu. Użytkownik wybiera opcję z menu:
   while (option != EXIT)
   {
      cout <<
      "Wybierz opcję:\n"
      "  1 | suma dwóch liczb całkowitych\n"
      "  2 | echo!\n"
      "  3 | sąsiedzi liczby X\n"
      "  4 | wyjdź"
      << endl;
      
      cin >> option;
      
      switch (option)
      {
         case SUMA: suma();
            break;
         case ECHO: echo();
            break;
         case NEIGHBOUR: neighbour();
            break;
         case ERROR:
            cin.clear();
            cin.ignore();
            cout << "Wybrana została niepoprawna opcja." << endl;
            break;
         case CONTINUE:
         default:
            continue;
      }
   }
   
   return 0;
}

void suma()
{
   // a) program pobiera dwie liczby całkowite i oblicza ich sumę, wyświetla wynik na ekran.
   int a, b;
   cout << "Podaj liczby a i b: ";
   cin >> a >> b;
   cout << a << " + " << b << " = " << a+b << endl;
}

void echo()
{   
   // b) program wyświetla tekst z użyciem podanej danej np.:
   // jeśli użytkownik napisał literę C, wyświetla „Napisałeś literę C”
   string input;
   cout << "Napisz coś: ";
   cin >> input;
   cout << "Napisałeś: " << input << endl;
}

void neighbour()
{
   // c) pobiera od użytkownika liczbę i wyświetla większą oraz mniejszą o jeden.
   float input;
   cout << "Podaj liczbę X: ";
   cin >> input;
   cout << input << " - 1 = " << input-1 << '\n';
   cout << input << " + 1 = " << input+1 << endl;
}