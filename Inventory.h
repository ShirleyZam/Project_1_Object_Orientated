#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <string>
#include "Flavor.h"
#include "Exceptions.h"

using namespace std;

class Inventory{
private:
    vector<Flavor*> flavors;
    int* scoopsArray;
    int flavorCount;
    
    int findFlavorIndex(const string& name) const;
    static string toLower(const string& s);

public:
    
Inventory();
~Inventory();

//Operations
void addFlavor(Flavor* flavor, int initalScoops);
void deleteFlavor(const string& name);

double sellScoops(const string& name, int scoops);
void restock(const string& name, int scoops);

const Flavor* findFlavor(const string& name) const;
int getScoopsAvailable(const string& name) const;

int getFlavorCount() const {return flavorCount; }
const vector<Flavor*>& getFlavors() const {return flavors; }

friend ostream& operator<<(ostream& os, const Inventory&);
};

#endif 
