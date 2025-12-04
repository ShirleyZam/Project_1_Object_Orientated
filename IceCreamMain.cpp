#include <iostream>
#include <vector>
#include <limits>
#include <exception>

using namespace std; 

//Header files that need to be included
#include "Flavor.h"
#include "Inventory.h"
#include "Filemanager.h"
#include "Order.h"
#include "Stockreport.h"
#include "Exceptions.h"

//The constant strings represent the FILE NAMES where the data 
//is stored and it's constant so it cannot be modified throughout the program
const string INVENTORY_FILE = "inventory.txt";
const string SALES_FILE = "sales.txt";

//Function to display the menu
void showMenu(){
    cout << "\n===== Ice Cream Shop Menu =====\n";
    cout << "1. Add flavor\n";
    cout << "2. Delete flavor\n";
    cout << "3. Restock flavor\n";
    cout << "4. Sell scoops \n";
    cout << "5. Show Inventory \n";
    cout << "6. Show stock report (uses Stats)\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

int main(){
    //Creates inventory object that stores all flavors and bucket sizes
    Inventory inv;
    //Creates vector that keeps all orders that happened during CURRENT runtime
    vector<Order> orders; 

    //Try is utilized to safely open a file, if the file fails it displays an exception
    try {
        // Static Method: exists only one time for the entire program
        // loadInventory won't rely on FileManager object, so there isn't a need to create an object 
        FileManager::loadInventory(inv, INVENTORY_FILE);
        FileManager::loadSales(orders, SALES_FILE); 

        cout << "Inventory and sales loaded.\n";
    } catch (const runtime_error& e){ // Catch only runs when there is a runtime_error from FileManager
        // Shows a warning message when there is an issue with the file it wants to open (e.what describes the error)
        cout << "Warning while loading files: " << e.what() << "\n";
    }

    int choice = -1; //user menu choice

    //while loop keeps the menu running until the user decides to exit (0)
    while(true){
        showMenu(); //displays the menu each run
        cin >> choice; //reads the users choice 

        //Input Validation if the user types something that
        // isn't a number, error flags are raised and cleared
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input. Please enter a number.\n";

            continue; // goes back to the beginning of the loop
        }

        if(choice == 0){
            try{
            //Try is used to safely open the file
            //if successful the program saves the inventory before stopping
                FileManager::saveInventory(inv, INVENTORY_FILE);
                cout << "Inventory saved to file.\n";
            } catch (const runtime_error& e){
                // error message if it is not able to open the file
                cout << "Error saving inventory: " << e.what() << "\n";
            }
            cout << "Bye!\n";
            break; // exits the while loop
        }
        //Choice to add a new flavor
        if(choice == 1){
            string name;
            double price;
            int scoops;
            int typeChoice; 

            cout << "Enter flavor name: ";
            cin >> ws; //whitespace skipper from <istream>
            //skips all whitespace characters: spaces tabs newlines etc.
            getline(cin,name);

            cout << "Enter price per scoop: "; 
            cin >> price; 

            cout << "How many scoops are in this bucket (0-10)?";
            cin >> scoops;

            cout << "Enter type (1 = Regular, 2 = Seasonal): ";
            cin >> typeChoice; 

            // Pointer points to a polymorphic flavor
            Flavor* f = nullptr;

            // Creates the correct derived class dynamically
            if (typeChoice == 2){
                
                f = new SeasonalFlavor(name,price,10,0.20);
            } else {
                f = new RegularFlavor(name,price);
            }
            // Adds it to inventory
            inv.addFlavor(f, scoops);
            cout << "Flavor added with bucket size = 10 scoops. \n";
        }
        //This deletes a flavor
        else if (choice == 2){ 
            string name; 
            cout << "Enter flavor name to delete: ";
            cin >> ws;
            getline(cin, name); 

            //Try to open the file and delete the requested flavor
            try{
                inv.deleteFlavor(name);
                cout << "Flavor deleted. \n";
            } catch (const FlavorNotFoundException& e){
                // If the file cannot be opened show an error message
                cout << "Error: " << e.what() << "\n";
            }
        } 
        //Restock a flavor 
        else if (choice == 3){
            string name;
            int amount; 
            
            cout << "Enter flavor name to restock: ";
            cin >> ws;
            getline(cin,name);

            cout << "Enter number of scoops to add: ";
            cin >> amount; 

            try {
                //Restocks flavor if file can be opened
                inv.restock(name, amount);
                cout << "Flavor restocked.\n";   
                }catch(const FlavorNotFoundException& e){
                //Shows an error message if it cannot
                    cout << "Error: " << e.what() << "\n";
                }
        }
        //Sell scoops 
        //Creates an Order and Updates inventory 
        else if(choice == 4){
            string name; 
            int scoops;
            cout << "Enter flavor name to sell: ";
            cin >> ws; 
            getline(cin, name);

            cout << "How many scoops? "; 
            cin >> scoops;

            try{
                double total = inv.sellScoops(name, scoops);
                cout << "Order total: $" << total << "\n";

                //Creates an order object
                Order ord(name, scoops, total); 

                //Save to the vector to store
                orders.push_back(ord); 

                try{
                    //Writes the saved infomration to the file 
                    FileManager::appendSale(ord, SALES_FILE);
                } catch (const runtime_error& e){
                    cout << "Enter writing sale " << e.what() << "\n";
                }
                } catch(const FlavorNotFoundException& e){
                    cout << "Error: " << e.what() << "\n";
                } catch(const OutOfStockException& e){
                    cout << "Error: " << e.what() << "\n";
                }
        } //Prints the entire inventory
        else if (choice == 5) {
            cout << inv;
        } 
        //Creates a Stock report uses Stats<T>
        else if (choice == 6){
            if (orders.empty()) {
                cout << "No sales yet. Make some sales first \n";
            } else {
                //Creates StockReport using vectors
                StockReport rep(orders);
                // Virtual polymorphic rreport generation
                rep.createReport();
            }
        } else {
            //Invalid option if user input does not match the menu 
            cout << "Unknown option. Please choose again.\n";
        }
    }

    return 0;
}