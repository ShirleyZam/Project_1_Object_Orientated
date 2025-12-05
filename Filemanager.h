// Rejuana Afrin
// 11/05/2025

#ifndef FILEMANAGER_H // this file is uncluded but only once
#define FILEMANAGER_H    //define the header guard

#include <string>
#include <vector>
#include "Inventory.h"
#include "Order.h"


using namespace std;

class FileManager { // it will handle file writing and reading


public:   // this can be use for outside of the functions

    static void saveInventory (const Inventory& data, const string& filename); // it will save inventory data into a file

    static void loadInventory (Inventory& data, const string& filename); // it will load inventory data from a file

    static void appendSale (const Order& order, const string& filename); // it will add a new sale of the order to the file

    static void loadSales (vector < Order >& orders, const string& filename); // here it will load all orders from a file



}; // end of the filemanager class



#endif // FILEMANAGER_H and close the header guard
