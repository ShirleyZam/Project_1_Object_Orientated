#include "Filemanager.h"

 #include <fstream>

 #include <sstream>

 #include "Flavor.h"
 
using namespace std;
 
void FileManager::saveInventory(const Inventory& inventory, const string& filename) {

     ofstream outFile(filename);

     if (!outFile.is_open()) {

         throw runtime_error("Cannot open inventory file for writing.");

     }
 
    const vector<Flavor*>& flavorList = inventory.getFlavors();
 
    for (size_t i = 0; i < flavorList.size(); i++) {

         Flavor* f = flavorList[i];

         outFile << f->getName() << "|"
<< f->getPrice() << "|"
<< f->getBucketSize() << "|"
<< inventory.getScoopsAvailable(f->getName()) << "|"
<< f->getType()
<< "\n";

     }

 }
 
void FileManager::loadInventory(Inventory& data, const string& filename) {

     ifstream inFile(filename);

     if (!inFile.is_open()) {

         // If file doesn't exist, just start with empty inventory

         return;

     }
 
    string line;

     while (getline(inFile, line)) {

         stringstream ss(line);
 
        string name;

         string priceStr;

         string bucketStr;

         string scoopsStr;

         string type;
 
        getline(ss, name, '|');

         getline(ss, priceStr, '|');

         getline(ss, bucketStr, '|');

         getline(ss, scoopsStr, '|');

         getline(ss, type, '|');
 
        if (name.empty()) continue;
 
        double price = stod(priceStr);

         int bucket = stoi(bucketStr);

         int scoops = stoi(scoopsStr);
 
        Flavor* f = nullptr;

         if (type == "Regular") {

             f = new RegularFlavor(name, price, bucket);

         } else if (type == "Seasonal") {

             f = new SeasonalFlavor(name, price, bucket, 0.20);

         } else {

             f = new Flavor(name, price, bucket);

         }
 
        data.addFlavor(f, scoops);

     }

 }
 
void FileManager::appendSale(const Order& order, const string& filename) {

     ofstream outFile(filename, ios::app);

     if (!outFile.is_open()) {

         throw runtime_error("Cannot open sales file for writing.");

     }
 
    outFile << order.getflavorname() << "|"
<< order.getscoops() << "|"
<< order.gettotalprice()
<< "\n";

 }
 
void FileManager::loadSales(vector<Order>& orders, const string& filename) {

     ifstream inFile(filename);

     if (!inFile.is_open()) {

         return;

     }
 
    string line;

     while (getline(inFile, line)) {

         stringstream ss(line);
 
        string name;

         string scoopsStr;

         string priceStr;
 
        getline(ss, name, '|');

         getline(ss, scoopsStr, '|');

         getline(ss, priceStr, '|');
 
        if (name.empty()) continue;
 
        int scoops = stoi(scoopsStr);

         double price = stod(priceStr);
 
        Order order(name, scoops, price);

         orders.push_back(order);

     }

 }
