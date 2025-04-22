#include <iostream>
#include <vector>

using namespace std;

/* Exercise 5
   Write a program:
1) that uses a loop or/and switch, which also uses a single-dimensional array.
2) The program has to have a "business character".
   Ex.: menu of a computer repair service, warehouse etc..
*/

void showTopWareBar();
void showWare(vector<struct ware>&, unsigned int wareID);
void showWareWithTopBar(vector<struct ware>&, unsigned int wareID);
void showWarehouse(vector<struct ware>&);
void selectWare(vector<struct ware>&, unsigned int wareID);
int selectWares(vector<struct ware>&);
int findWare(vector<struct ware>&, unsigned int wareID);
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
   SELECT = 2,
   UPDATE = 3,
   ADD = 4,
   DELETE = 5,
   EXIT = 6,
   CONTINUE = 7,
};

int main(int argc, char* argv[])
{
   std::vector<struct ware> shopWarehouse ={
      {0, "Apples 1kg", 2.89, 3},
      {1, "Bananas 1kg", 6.09, 2},
      {2, "Candies 1kg", 21.49, 23},
      {3, "Carbonated canned soda 250ml", 3.19, 9},
      {4, "Carb. water 1l", 1.79, 4},
      {5, "Still water 1l", 1.59, 11},
      {6, "Candybar", 3.19, 10},
      {7, "Butter 100g", 5.99, 4},
      {8, "10 Eggs", 9.99, 6},
   };
   wareLastID = shopWarehouse.size() - 1;


   int option = CONTINUE;
   while (option != EXIT)
   {
      cout <<
      "Select an option:\n"
      "  X | Description\n"
      "  1 | Show warehouse | shorthand form (command chains allowed)\n"
      "  2 | Select articles | 2 <id> ... <id> ends with negative number\n"
      "  3 | Modify article | 3 <id> <new-price> <new-quantity>\n"
      "  4 | Add article | 4 <article_name> <price> <quantity>\n"
      "  5 | Delete article | 5 <id>\n"
      "  6 | Exit"
      << endl;

      cin >> option;

      switch (option)
      {
         case SHOW: showWarehouse(shopWarehouse);
            break;
         case SELECT:
         showTopWareBar();
         selectWares(shopWarehouse);
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
         cin.ignore(100, '\n');
         cout << "Invalid option." << endl;
      }
   }

   return 0;
}

void showTopWareBar() {
   cout << "ID\tArticle Name\t\t\tPrice\tQuantity" << endl;
   cout << "---------------------------------------------------------" << endl;
}

void showWare(vector<struct ware>& warehouse, unsigned int wareID) {
   if (wareID == ENTRY_NOT_FOUND) return;
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
   cout << "Current stock: " << endl;
   showTopWareBar();

   for (int i = 0; i < warehouse.size(); i++) {
      showWare(warehouse, i);
   }
}

int findWare(vector<struct ware>& warehouse, unsigned int wareID) {
   for (int i = 0; i < warehouse.size(); i++)
      if (warehouse[i].id == wareID)
         return i;
   cout << wareID << "\t\tNOT FOUND" << endl;
   return ENTRY_NOT_FOUND;
};

int selectWares(vector<struct ware>& warehouse) {
   int selectedID = 0;
   while (true) {
      cin >> selectedID;
      if (cin.fail()) return CIN_ERROR;
      if (selectedID < 0) return SUCCESS;
      selectWare(warehouse, selectedID);
   }
}

void selectWare(vector<struct ware>& warehouse, unsigned int wareID) {
   showWare(warehouse, findWare(warehouse, wareID));
};

int updateWare(vector<struct ware>& warehouse) {
   unsigned int wareID;
   unsigned int newWareQuantity;
   float newWarePrice;

   cout << "Enter the ID of the entry you want to modify: ";
   cin >> wareID;
   if (findWare(warehouse, wareID) == ENTRY_NOT_FOUND) return ENTRY_NOT_FOUND;
   
   showWareWithTopBar(warehouse, findWare(warehouse, wareID));

   cout << "Enter new Data: " << endl;
   cout << "<price> <quantity>" << endl;

   cin >> newWarePrice >> newWareQuantity;
   if (cin.fail()) return CIN_ERROR;
   
   if (newWarePrice < 0) {
      cout << "ERROR: Price cannot be negative" << endl;
      return OTHER_ERROR;
   }

   warehouse[findWare(warehouse, wareID)].price = newWarePrice;
   warehouse[findWare(warehouse, wareID)].quantity = newWareQuantity;

   showWareWithTopBar(warehouse, findWare(warehouse, wareID));
   cout << "Article with ID " << wareID << " has been successfully modified" << endl;
   return SUCCESS;
}

int addWare(vector<struct ware>& warehouse) {
   string wareName;
   unsigned int wareQuantity;
   float warePrice;

   cout << "Add article:\n";
   cout << "<article_name> <price> <quantity>" << endl;

   cin >> wareName >> warePrice >> wareQuantity;
   if (cin.fail()) return CIN_ERROR;

   if (warePrice < 0) {
      cout << "ERROR: Price cannot be negative" << endl;
      return OTHER_ERROR;
   }

   for (int i = 0; i < wareName.length(); i++)
      if (wareName[i] == '_')
         wareName[i] = ' ';

   wareLastID++;
   warehouse.push_back({wareLastID, wareName, warePrice, wareQuantity});

   showWareWithTopBar(warehouse, findWare(warehouse, wareLastID));
   cout << "Item with ID " << wareLastID << " has been successfully added" << endl;
   return SUCCESS;
}

int deleteWare(vector<struct ware>& warehouse) {
   unsigned int wareID;
   int wareI;

   cout << "Remove entry with ID: \n";

   cin >> wareID;
   if (cin.fail()) return CIN_ERROR;

   wareI = findWare(warehouse, wareID);
   if (wareI == ENTRY_NOT_FOUND) {
      cout << "Item with selected ID has not been found." << endl;
      return ENTRY_NOT_FOUND;
   }
   
   showWareWithTopBar(warehouse, wareI);
   warehouse.erase(warehouse.begin() + wareI);
   cout << "Entry with ID " << wareID << " has been successfully removed" << endl;
   return SUCCESS;
}