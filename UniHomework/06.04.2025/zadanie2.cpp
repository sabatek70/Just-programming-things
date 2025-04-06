#include <iostream>

/* ZADANIE 2
   Napisz program, który:
1) stworzy tablicę jednowymiarową,
2) następnie wypełni ją liczbami podanymi przez użytkownika.
3) W kolejnym kroku pomnoży każdy element tablicy * 2 JEŚLI jest on mniejszy niż 10 i zapisze wynik na miejscu liczby.
4) Następnie wyświetli tablicę użytkownikowi. 
*/

int main()
{
   using namespace std;
    
   int rozmiarTablicy;
   cout << "Podaj rozmiar tablicy: ";
   cin >> rozmiarTablicy;
    
   // 1) stworzy tablicę jednowymiarową,
   int tablica[rozmiarTablicy];
    
   // 2) następnie wypełni ją liczbami podanymi przez użytkownika.
   cout << "Podaj " << rozmiarTablicy << " elementów:" << endl;
   for (int i = 0; i < rozmiarTablicy; i++) {
      cin >> tablica[i];
   }
    
   // 3) W kolejnym kroku pomnoży każdy element tablicy * 2 JEŚLI jest on mniejszy niż 10 i zapisze wynik na miejscu liczby.
   for (int i = 0; i < rozmiarTablicy; i++) {
      if (tablica[i] < 10)
         tablica[i] *= 2;
   }
    
   // 4) Następnie wyświetli tablicę użytkownikowi. 
   for (int i = 0; i < rozmiarTablicy; i++) {
      cout << tablica[i] << ' ';
   }
    
   return 0;
}