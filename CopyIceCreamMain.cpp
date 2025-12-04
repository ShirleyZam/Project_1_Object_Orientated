#include <iostream>

 #include <vector>

 #include <limits>      // for numeric_limits

 #include <exception>

 using namespace std;
 
#include "Flavor.h"

 #include "Inventory.h"

 #include "Filemanager.h"

 #include "Order.h"

 #include "Stockreport.h"

 #include "Exceptions.h"
 
const string INVENTORY_FILE = "inventory.txt";

 const string SALES_FILE     = "sales.txt";
 
void showMenu() {

     cout << "\n===== Ice Cream Shop Menu =====\n";

     cout << "1. Add flavor\n";

     cout << "2. Delete flavor\n";

     cout << "3. Restock flavor\n";

     cout << "4. Sell scoops\n";

     cout << "5. Show inventory\n";

     cout << "6. Show stock report (uses Stats)\n";

     cout << "0. Exit\n";

     cout << "Choose an option: ";

 }
 
int main() {

     Inventory inv;

     vector<Order> orders;
 
    // ---- Load inventory and past sales at start ----

     try {

         FileManager::loadInventory(inv, INVENTORY_FILE);

         FileManager::loadSales(orders, SALES_FILE);

         cout << "Inventory and sales loaded.\n";

     } catch (const runtime_error& e) {

         cout << "Warning while loading files: " << e.what() << "\n";

     }
 
    int choice = -1;
 
    while (true) {

         showMenu();

         cin >> choice;
 
        // ---- Input validation for menu choice ----

         if (cin.fail()) {

             cin.clear();

             cin.ignore(numeric_limits<streamsize>::max(), '\n');

             cout << "Invalid input. Please enter a number.\n";

             continue;

         }
 
        if (choice == 0) {

             // ---- Save inventory and exit ----

             try {

                 FileManager::saveInventory(inv, INVENTORY_FILE);

                 cout << "Inventory saved to file.\n";

             } catch (const runtime_error& e) {

                 cout << "Error saving inventory: " << e.what() << "\n";

             }

             cout << "Goodbye!\n";

             break;

         }
 
                if (choice == 1) {

            // ---- Add flavor (manager action) ----

            string name;

            double price;

            int scoops;

            int typeChoice;
 
            cout << "Enter flavor name: ";

            cin >> ws;                 // eat leftover newline

            getline(cin, name);
 
            cout << "Enter price per scoop: ";

            cin >> price;
 
            // We no longer ask for bucket size.

            // Every bucket is always 10 scoops.

            cout << "How many scoops are currently in this bucket (0–10)? ";

            cin >> scoops;
 
            cout << "Enter type (1 = Regular, 2 = Seasonal): ";

            cin >> typeChoice;
 
            Flavor* f = nullptr;

            if (typeChoice == 2) {

                // seasonal, 20% discount example

                f = new SeasonalFlavor(name, price, 10, 0.20); // bucket forced to 10 anyway

            } else {

                f = new RegularFlavor(name, price); // bucket defaults to 10

            }
 
            inv.addFlavor(f, scoops);

            cout << "Flavor added with bucket size = 10 scoops.\n";

        }
 

         else if (choice == 2) {

             // ---- Delete flavor ----

             string name;

             cout << "Enter flavor name to delete: ";

             cin >> ws;

             getline(cin, name);
 
            try {

                 inv.deleteFlavor(name);

                 cout << "Flavor deleted.\n";

             } catch (const FlavorNotFoundException& e) {

                 cout << "Error: " << e.what() << "\n";

             }

         }

         else if (choice == 3) {

             // ---- Restock flavor ----

             string name;

             int amount;
 
            cout << "Enter flavor name to restock: ";

             cin >> ws;

             getline(cin, name);
 
            cout << "Enter number of scoops to add: ";

             cin >> amount;
 
            try {

                 inv.restock(name, amount);

                 cout << "Flavor restocked.\n";

             } catch (const FlavorNotFoundException& e) {

                 cout << "Error: " << e.what() << "\n";

             }

         }

         else if (choice == 4) {

             // ---- Sell scoops (create Order + append to sales file) ----

             string name;

             int scoops;
 
            cout << "Enter flavor name to sell: ";

             cin >> ws;

             getline(cin, name);
 
            cout << "How many scoops? ";

             cin >> scoops;
 
            try {

                 double total = inv.sellScoops(name, scoops);

                 cout << "Order total: $" << total << "\n";
 
                // Make an Order and store it in memory

                 Order ord(name, scoops, total);

                 orders.push_back(ord);
 
                // Append sale to file

                 try {

                     FileManager::appendSale(ord, SALES_FILE);

                 } catch (const runtime_error& e) {

                     cout << "Error writing sale: " << e.what() << "\n";

                 }
 
            } catch (const FlavorNotFoundException& e) {

                 cout << "Error: " << e.what() << "\n";

             } catch (const OutOfStockException& e) {

                 cout << "Error: " << e.what() << "\n";

             }

         }

         else if (choice == 5) {

             // ---- Show inventory ----

             cout << inv;

         }

         else if (choice == 6) {

             // ---- Show stock report (uses Report + Stats template) ----

             if (orders.empty()) {

                 cout << "No sales yet. Make some sales first.\n";

             } else {

                 StockReport rep(orders);

                 rep.createReport();

             }

         }

         else {

             cout << "Unknown option. Please choose again.\n";

         }

     }
 
    return 0;

 }
