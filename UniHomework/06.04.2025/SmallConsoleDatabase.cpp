#include <iostream>
#include <vector>

using namespace std;

/* 
   A small database(?) I OVERdid for an assigment
*/

void showTopWareBar();
void showWare(vector<struct ware>&, unsigned int wareID);
void showWareWithTopBar(vector<struct ware>&, unsigned int wareID);
void showWarehouse(vector<struct ware>&);
void selectWare(vector<struct ware>&, unsigned int wareID);
void setCurrentDate();
int selectWares(vector<struct ware>&);
int locateWareID(vector<struct ware>&, unsigned int wareID);
int updateWare(vector<struct ware>&);
int addWare(vector<struct ware>&);
int deleteWare(vector<struct ware>&);
int findWareByName(vector<struct ware>&);


typedef struct {
   int day;
   int month;
   int year;
} Date;

struct ware {
   unsigned int id;
   string name;
   float price;
   unsigned int quantity;
   Date date;
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
   SETDATE = 6,
   FINDNAME = 7,
   EXIT = 8,
   CONTINUE = 9,
};

Date CURRENT_DATE = {1, 1, 2025};

int main(int argc, char* argv[])
{
   std::vector<struct ware> shopWarehouse ={
      {0, "Apples 1kg", 2.89, 3, {1,01,2024}},
      {1, "Bananas 1kg", 6.09, 2, {1,01,2024}},
      {2, "Candies 1kg", 21.49, 23, {1,01,2024}},
      {3, "Carbonated canned soda 250ml", 3.19, 9, {1,01,2024}},
      {4, "Carb. water 1l", 1.79, 4, {1,01,2024}},
      {5, "Still water 1l", 1.59, 11, {1,01,2024}},
      {6, "Candybar", 3.19, 10, {1,01,2024}},
      {7, "Butter 100g", 5.99, 4, {1,01,2024}},
      {8, "10 Eggs", 9.99, 6, {1,01,2024}},
   };
   wareLastID = shopWarehouse.size() - 1;


   int option = CONTINUE;
   while (option != EXIT)
   {
      cout <<
      "Current date: " << CURRENT_DATE.day << '.' << CURRENT_DATE.month << '.' << CURRENT_DATE.year << '\n' <<
      "Select an option:\n"
      "  X | Description\n"
      "  1 | Show warehouse | shorthand form (command chains allowed)\n"
      "  2 | Show articles by ID | 2 <id> ... <id> ends with negative number\n"
      "  3 | Modify article | 3 <id> <new-price> <new-quantity>\n"
      "  4 | Add article | 4 <article_name> <price> <quantity>\n"
      "  5 | Delete article | 5 <id>\n"
      "  6 | Set current date | 6 <day> <month> <year>\n"
      "  7 | Search for article by Name | 6 <name>\n"
      "  8 | Exit"
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
         case SETDATE: setCurrentDate();
            break;
         case FINDNAME: findWareByName(shopWarehouse);
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

void setCurrentDate() {
   int MonthsDays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   cout << "<day> <month> <year>" << endl;
   cin >> CURRENT_DATE.day >> CURRENT_DATE.month >> CURRENT_DATE.year;

   // HERE STARTS UNNECESSARY FANCY
      
   // Just in case someone tried to insert an impossible date
   // I decided it would still work.
   // negative numbers = backwards in time.

   // Exchange additional months for years.
   while (CURRENT_DATE.month > 12) {
       CURRENT_DATE.month -= 12;
       CURRENT_DATE.year += 1;
   }
   // Negative months exchange
   while (CURRENT_DATE.month < 1) {
      CURRENT_DATE.month += 12;
      CURRENT_DATE.year -= 1;
   }
   
   // Exchange remaining days for months and years.
   if (CURRENT_DATE.day < 0)
      // Negative days variant
      while (CURRENT_DATE.day < 0)
      {
         cout << CURRENT_DATE.day << endl;
         int currentMonthIndex = CURRENT_DATE.month - 1;
         if (currentMonthIndex < 1) currentMonthIndex = 12;
         
         if ((CURRENT_DATE.year % 4 == 0 && CURRENT_DATE.year % 100 != 0) || (CURRENT_DATE.year % 400 == 0))
            MonthsDays[1] = 29;
         else MonthsDays[1] = 28;
         
         CURRENT_DATE.day += MonthsDays[currentMonthIndex];
         CURRENT_DATE.month--;
         if (CURRENT_DATE.month < 1 || CURRENT_DATE.month == 0) {
             CURRENT_DATE.month = 12;
             CURRENT_DATE.year -= 1;
         }
      }
   else
      // Positive days variant
      while (CURRENT_DATE.day > MonthsDays[CURRENT_DATE.month - 1])
      {
         int currentMonthIndex = CURRENT_DATE.month - 1;
         if (currentMonthIndex > 11) currentMonthIndex = 0;
         
         if ((CURRENT_DATE.year % 4 == 0 && CURRENT_DATE.year % 100 != 0) || (CURRENT_DATE.year % 400 == 0))
            MonthsDays[1] = 29;
         else MonthsDays[1] = 28;
         
         CURRENT_DATE.day -= MonthsDays[currentMonthIndex];
         CURRENT_DATE.month++;
         if (CURRENT_DATE.month > 12 || CURRENT_DATE.month == 0) {
             CURRENT_DATE.month = 1;
             CURRENT_DATE.year += 1;
         }
      }
      
   // Not ideal, but no zeros allowed!
   if (CURRENT_DATE.day == 0) CURRENT_DATE.day = 1;
   if (CURRENT_DATE.month == 0) CURRENT_DATE.month = 1;
   if (CURRENT_DATE.year == 0) CURRENT_DATE.year = 1;
}

   // Prints the top bar
void showTopWareBar() {
   cout << "ID\tArticle Name\t\t\tPrice\tQuantity\tDate" << endl;
   cout << "-------------------------------------------------------------------------" << endl;
}

   // Prints one entry
void showWare(vector<struct ware>& warehouse, unsigned int wareID) {
   if (wareID == ENTRY_NOT_FOUND) return;
   cout << warehouse[wareID].id << '\t' << warehouse[wareID].name;
   for (int j = 0; j < 4 - warehouse[wareID].name.length() / 8; j++)
      cout << '\t';
   cout << warehouse[wareID].price << '\t' << warehouse[wareID].quantity << "\t\t"
   << warehouse[wareID].date.day << '.' << warehouse[wareID].date.month << '.' << warehouse[wareID].date.year << endl; 
}

void showWareWithTopBar(vector<struct ware>& warehouse, unsigned int wareID) {
   showTopWareBar();
   showWare(warehouse, wareID);
}

   // Prints all warehouse
void showWarehouse(vector<struct ware>& warehouse) {
   cout << "Current stock: " << endl;
   showTopWareBar();

   for (int i = 0; i < warehouse.size(); i++) {
      showWare(warehouse, i);
   }
}

   // Translates given ID to its respective location vector offset
int locateWareID(vector<struct ware>& warehouse, unsigned int wareID) {
   for (int i = 0; i < warehouse.size(); i++)
      if (warehouse[i].id == wareID)
         return i;
   cout << wareID << "\t\tNOT FOUND" << endl;
   return ENTRY_NOT_FOUND;
};

   // Enters article selection mode, negative number exits
int selectWares(vector<struct ware>& warehouse) {
   int selectedID = 0;
   while (true) {
      cin >> selectedID;
      if (cin.fail()) return CIN_ERROR;
      if (selectedID < 0) return SUCCESS;
      selectWare(warehouse, selectedID);
   }
}
   // Select singular article by ID and show it
void selectWare(vector<struct ware>& warehouse, unsigned int wareID) {
   showWare(warehouse, locateWareID(warehouse, wareID));
};

   // Update an article
   // Only price and quantity can be modified
   // Date will update according to current set date
int updateWare(vector<struct ware>& warehouse) {
   unsigned int wareID;
   unsigned int newWareQuantity;
   float newWarePrice;

   cout << "Enter the ID of the entry you want to modify: ";
   cin >> wareID;
   if (locateWareID(warehouse, wareID) == ENTRY_NOT_FOUND) return ENTRY_NOT_FOUND;
   
   showWareWithTopBar(warehouse, locateWareID(warehouse, wareID));

   cout << "Enter new Data: " << endl;
   cout << "<price> <quantity>" << endl;

   cin >> newWarePrice >> newWareQuantity;
   if (cin.fail()) return CIN_ERROR;
   
   if (newWarePrice < 0) {
      cout << "ERROR: Price cannot be negative" << endl;
      return OTHER_ERROR;
   }

   warehouse[locateWareID(warehouse, wareID)].price = newWarePrice;
   warehouse[locateWareID(warehouse, wareID)].quantity = newWareQuantity;
   warehouse[locateWareID(warehouse, wareID)].date = CURRENT_DATE;

   showWareWithTopBar(warehouse, locateWareID(warehouse, wareID));
   cout << "Article with ID " << wareID << " has been successfully modified" << endl;
   return SUCCESS;
}


   // Add an article
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
   warehouse.push_back({wareLastID, wareName, warePrice, wareQuantity, CURRENT_DATE});

   showWareWithTopBar(warehouse, locateWareID(warehouse, wareLastID));
   cout << "Item with ID " << wareLastID << " has been successfully added" << endl;
   return SUCCESS;
}

   // Delete Entry
int deleteWare(vector<struct ware>& warehouse) {
   unsigned int wareID;
   int wareI;

   cout << "Remove entry with ID: \n";

   cin >> wareID;
   if (cin.fail()) return CIN_ERROR;

   wareI = locateWareID(warehouse, wareID);
   if (wareI == ENTRY_NOT_FOUND) {
      cout << "Item with selected ID has not been found." << endl;
      return ENTRY_NOT_FOUND;
   }
   
   showWareWithTopBar(warehouse, wareI);
   warehouse.erase(warehouse.begin() + wareI);
   cout << "Entry with ID " << wareID << " has been successfully removed" << endl;
   return SUCCESS;
}

   // Find article by name
int findWareByName(vector<struct ware>& warehouse) {
   string wareName;
   cout << "Enter the Name of the entry you want to modify: ";
   cin >> wareName;
   cout << endl;

   showTopWareBar();
   for (int i = 0; i < warehouse.size(); i++) {
      if (warehouse[i].name.find(wareName) == string::npos)
         continue;
      selectWare(warehouse, i);
   }
   
   return ENTRY_NOT_FOUND;
}