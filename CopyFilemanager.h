#ifndef FILEMANAGER_H

 #define FILEMANAGER_H
 
#include <string>

 #include <vector>

 #include "Inventory.h"

 #include "Order.h"
 
using namespace std;
 
class FileManager {

 public:

     static void saveInventory(const Inventory& data, const string& filename);

     static void loadInventory(Inventory& data, const string& filename);
 
    static void appendSale(const Order& order, const string& filename);

     static void loadSales(vector<Order>& orders, const string& filename);

 };
 
#endif // FILEMANAGER_H
