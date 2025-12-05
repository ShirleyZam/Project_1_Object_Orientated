#include "Filemanager.h"
#include <fstream> // it will allow to read and write 
#include <sstream> // it will allow to split easily
#include "Flavor.h" // it will include flavor and it's subclasses

using namespace std;


// it will save the inv to a file
void FileManager::saveInventory(const Inventory& inventory, const string& filename) { // it will save the inventory to a file

    ofstream outFile(filename); // it will open the file for writing 

    if (!outFile.is_open()) { // it will check if the file failed to open

        throw runtime_error("Cannot open inventory file for writing."); // it will show the error message

    }

    const vector<Flavor*>& flavorList = inventory.getFlavors(); // to get all flavors from inventory class

    for (size_t i = 0; i < flavorList.size(); i++) { // it will get the whole list of flavor from inv class 

        Flavor* f = flavorList[i]; // to get the current flavor list 


        // it will write all the flaor's info to the file and seperated by "|"
        outFile << f->getName() << "|"
            << f->getPrice() << "|"
            << f->getBucketSize() << "|"
            << inventory.getScoopsAvailable(f->getName()) << "|"
            << f->getType()
            << "\n";     // it's a newline character that means new line or flavor will start now

    }

}

// it will load the inv from a saved file
void FileManager::loadInventory(Inventory& data, const string& filename) {

    ifstream inFile(filename);

    if (!inFile.is_open()) {

        // If file doesn't exist, it will just start with empty inventory



        return;
    }

    string line; // it means to hold eash line

    while (getline(inFile, line)) { // it read files line by line

        stringstream ss(line); // it will prepare to split the lines
        string name; // name of the flavors
        string priceStr; // text and shows price
        string bucketStr; // text bucket size
        string scoopsStr; // text counting scoops
        string type;    // text flavor type 
   
        
        
        getline(ss, name, '|');  // read names
        getline(ss, priceStr, '|'); // it will read price
        getline(ss, bucketStr, '|'); // it will read bucket size
        getline(ss, scoopsStr, '|'); // it will read the scoops 
        getline(ss, type, '|'); // read type 

        if (name.empty()) continue; // it will skip empty lines

        double price = stod(priceStr); // it will convert price text to numbers
        int bucket = stoi(bucketStr); // it will convert bucket text to numbers
        int scoops = stoi(scoopsStr); // it will convert scoops text to numbers
        Flavor* f = nullptr; // it's a pointer to a new flavor

        if (type == "Regular") { // if regular flavor  

            f = new RegularFlavor(name, price, bucket); // it will show this
        }
        else if (type == "Seasonal") { // if it's seasonal flavor

            f = new SeasonalFlavor(name, price, bucket, 0.20); // it will show default discount 20% off
        }
        else {   // if the type is unknown

            f = new Flavor(name, price, bucket); // create base flavor

        }

        data.addFlavor(f, scoops); // it will add the flavor and scoops to inv

    }

}

void FileManager::appendSale ( const Order& order, const string& filename ) { // it will add the new sale to the sales file
    ofstream outFile(filename, ios::app); // it will open file to the append mode and write new stuff at the end of it

    if (!outFile.is_open()) { // if  the file can't open

        throw runtime_error( "Cannot open sales file for writing." ); // it will show an error

    }

    outFile << order.getflavorname() << "|" // it will write order info into the file
        << order.getscoops() << "|"
        << order.gettotalprice()
        << "\n"; // will add new line after each order

}



void FileManager::loadSales(vector<Order>& orders, const string& filename) { // will load all orders from the file

    ifstream inFile(filename); // it will open files for reading

    if (!inFile.is_open()) { // if the file not found 

        return; // it will just return with an empty list

    }

    string line; // it holds each lines of the files

    while (getline(inFile, line)) { // it read each lines

        stringstream ss(line);  // it always prepare lines for splitting

        string name; // text name of the flavor 
        string scoopsStr; // text number of scoops
        string priceStr; // price text

        getline(ss, name, '|'); // it will read names 
        getline(ss, scoopsStr, '|'); // it will read scoops
        getline(ss, priceStr, '|'); // it will read the prices

        if (name.empty()) continue; // it will help to skip empty lines

        int scoops = stoi(scoopsStr); // it will convert scoops to numbers
        double price = stod(priceStr); // it will convert price to numbers
        Order order(name, scoops, price); // it will create new order 
        orders.push_back(order); // it will add to the order list

    }

}
