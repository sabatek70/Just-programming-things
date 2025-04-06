#include <iostream>
#include <vector>

using namespace std;

/* ZADANIE 5
   Napisz program:
1) używający pętli lub/i instrukcji switch, a także tablicy jednowymiarowej.
2) Program musi mieć charakter biznesowy.
   Np.: menu serwisu komputerowego, magazyn etc..
*/

void showTopWareBar();
void showWare(vector<struct ware>&, unsigned int wareID);
void showWareWithTopBar(vector<struct ware>&, unsigned int wareID);
void showWarehouse(vector<struct ware>&);
int updateWare(vector<struct ware>&);
int addWare(vector<struct ware>&);
int deleteWare(vector<struct ware>&);

struct ware {
   unsigned int id;
   string name;
   float price;
   unsigned int quantity;
};
unsigned int wareLastID;

enum exit_code {
   SUCCESS = 1,
   CIN_ERROR = -1,
   ENTRY_NOT_FOUND = -2,
   OTHER_ERROR = -3,
};

enum options {
   ERROR = 0,
   SHOW = 1,
   UPDATE = 2,
   ADD = 3,
   DELETE = 4,
   EXIT = 5,
   CONTINUE = 6,
};

int main(int argc, char* argv[])
{
   std::vector<struct ware> shopWarehouse ={
      {0, "Jabłka 1kg", 2.89, 3},
      {1, "Banany 1kg", 6.09, 2},
      {2, "Cukierki 1kg", 21.49, 23},
      {3, "Napój gaz. pusz. 250ml", 3.19, 9},
      {4, "Woda gaz. 1l", 1.79, 4},
      {5, "Woda niegaz.", 1.59, 11},
      {6, "Batonik", 3.19, 10},
      {7, "Masło 100g", 5.99, 4},
      {8, "Jajka 10szt", 9.99, 6},
   };
   wareLastID = shopWarehouse.size();


   int option = CONTINUE;
   while (option != EXIT)
   {
      cout <<
      "Wybierz opcję:\n"
      "  1 | Pokaż magazyn\n"
      "  2 | Modyfiku artykuł\n"
      "  3 | Dodaj artykuł\n"
      "  4 | Usuń artykuł\n"
      "  5 | wyjdź"
      << endl;

      cin >> option;

      switch (option)
      {
         case SHOW: showWarehouse(shopWarehouse);
            break;
         case UPDATE: updateWare(shopWarehouse);
            break;
         case ADD: addWare(shopWarehouse);
            break;
         case DELETE: deleteWare(shopWarehouse);
            break;
         case ERROR:
         case CONTINUE:
         default:
            break;
      }
      if (cin.fail()) {
         cin.clear();
            cin.ignore();
            cout << "Wybrana została niepoprawna opcja." << endl;
      }
   }

   return 0;
}

void showTopWareBar() {
   cout << "ID\tNazwa artykułu\t\t\tcena\tilość" << endl;
   cout << "---------------------------------------------------------" << endl;
}

void showWare(vector<struct ware>& warehouse, unsigned int wareID) {
   cout << warehouse[wareID].id << '\t' << warehouse[wareID].name;
   for (int j = 0; j < 4 - warehouse[wareID].name.length() / 8; j++)
      cout << '\t';
   cout << warehouse[wareID].price << '\t' << warehouse[wareID].quantity << endl; 
}

void showWareWithTopBar(vector<struct ware>& warehouse, unsigned int wareID) {
   showTopWareBar();
   showWare(warehouse, wareID);
}

void showWarehouse(vector<struct ware>& warehouse) {
   cout << "Stan magazynu: " << endl;
   showTopWareBar();

   for (int i = 0; i < warehouse.size(); i++) {
      showWare(warehouse, i);
   }
}

int updateWare(vector<struct ware>& warehouse) {
   unsigned int wareID;
   unsigned int newWareQuantity;
   float newWarePrice;

   cout << "Podaj ID modyfikowanego artykułu: ";
   cin >> wareID;

   showWareWithTopBar(warehouse, wareID);

   cout << "Wprowadź nowe dane: " << endl;
   cout << "<cena> <ilość>" << endl;

   cin >> newWarePrice >> newWareQuantity;
   if (cin.fail()) return CIN_ERROR;
   
   if (newWarePrice < 0) {
      cout << "BŁĄD: Cena nie może być ujemna." << endl;
      return OTHER_ERROR;
   }

   warehouse[wareID].price = newWarePrice;
   warehouse[wareID].quantity = newWareQuantity;

   cout << "Artykuł został zmodyfikowany pomyślnie." << endl;
   showWareWithTopBar(warehouse, wareID);
   return SUCCESS;
}

int addWare(vector<struct ware>& warehouse) {
   string wareName;
   unsigned int wareQuantity;
   float warePrice;

   cout << "Dodaj artykuł:\n";
   cout << "<Nazwa_artykułu> <cena> <ilość>" << endl;

   cin >> wareName >> warePrice >> wareQuantity;
   if (cin.fail()) return CIN_ERROR;

   if (warePrice < 0) {
      cout << "BŁĄD: Cena nie może być ujemna." << endl;
      return OTHER_ERROR;
   }

   warehouse.push_back({wareLastID+1, wareName, warePrice, wareQuantity});
   wareLastID++;

   cout << "Artykuł o ID " << wareLastID << " zostało pomyślnie dodane";
   showWareWithTopBar(warehouse, wareLastID);
   return SUCCESS;
}

int deleteWare(vector<struct ware>& warehouse) {
   unsigned int wareID;

   cout << "Usuń artykuł o ID: \n";

   cin >> wareID;
   if (cin.fail()) return CIN_ERROR;

   for (int i = 0; i < warehouse.size(); i++) {
      if (warehouse[i].id == wareID) {
         warehouse.erase(warehouse.begin()+i);
         cout << "Artykuł o ID " << wareID << " został pomyślnie usunięte" << endl;
         return SUCCESS;
      }
   }
    
   cout << "Nie znaleziono artykułu o takim ID" << endl;
   return ENTRY_NOT_FOUND;
}