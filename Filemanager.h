#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Inventory.h"
#include "Order.h"
#include <string>
#include <vector>

using namespace std;

class FileManager {
public:

    // for saving and loading inventory data
    
    static void saveInventory(const Inventory & data, const string& filename);
    static void loadInventory(Inventory & data, const string& filename);

    // sales for save and loads
    
    static void appendSale(const Order& order, const string& filename);
    static void loadSales(vector< Order > & orders, const string& filename);
};

#endif
