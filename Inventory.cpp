#include "Inventory.h"
#include <cctype>

using namespace std;

// Help funtions

string Inventory::toLower(const string& s){
    string result;
    result.reserve(s.size());
    for (size_t i=0; i < s.size(); i++){
        unsigned char ch = static_cast<unsigned char>(s[i]);
        result.push_back(static_cast<char>tolower(static_cast<unsigned char>(c)));
    }
    return result;
}

int Inventory::findFlavorIndex(const string& name) const{
    string target = toLower(name);
    
    for (int i=0; i< flavorCount; i++){
        if (toLower(flavors[i]->getName())== target){
            return i;
        }
    }
    return -1; 
}

Inventory::Inventory()
: scoopsArray(nullptr), flavorCount(0){}

Inventory::~Inventory(){
    // this is to delete all flavors
    for (int i = 0; i < flavorCount; i++){
        delete flavors[i];
    }
    flavors.clear();
    delete[] scoopsArray;
    scoopsArray = nullptr;
}

 void Inventory::addFlavor(Flavor* flavor, int initialScoops){
    if(flavor == nullptr){
        return;
    }
    flavors.push.back(flavor);

    int newCount = flavorCount + 1;
    int* newArray = new int[newCount];

    for (int i=0; i < flavorCount; i++){
        newArray[i] = scoopsArray[i];
    }

    if (initialScoops < 0){
        initialScoops = 0;
    }

    newArray[newCount - 1] = initialScoops;

    delete[] scoopsArray;
    scoopsArray = newArray;
    flavorCount = newCount;
 }

 void Inventory::deleteFlavor(const string& name) {
    int index = findFlavorIndex(name);
    if (index == -1) {
        throw FlavorNotFoundException(name);
    }

    delete flavors[index];

    flavors.erase(flavors.begin() + index);

    int newCount = flavorCount - 1;

    if (newCount == 0) {
        delete[] scoopsArray;
        scoopsArray = nullptr;
        flavorCount = 0;
        return;
    }

    int* newArray = new int[newCount];
    int j = 0;
    for (int i = 0; i < flavorCount; i++) {
        if (i == index) continue;
        newArray[j] = scoopsArray[i];
        j++;
    }

    delete[] scoopsArray;
    scoopsArray = newArray;
    flavorCount = newCount;
}

 double Inventory::sellScoops(const string& name, int sccops){
    if(sccops <= 0){
        return 0.0;
    }
    int index = findFlavorIndex(name);
    if(index == -1){
        throw FlavornotFoundException(name);
    }

    if (scoopsArray[index] < scoops){
        throw OutofStockException(name);
    }
    scoopsArray[index] -= scoops;
    return flavors[index]->priceCalc(scoops);
 }

 void Inventory::restock(const string& name, int scoops){
    if(scoops <= 0){
        return;
    }
    int index = findFlavorIndex(name);
    if (index == -1){
        throw FlavorNotFoundException(name);
    }
    scoopsArray[index] += scoops;
 }

 const Flavor* Inventory::findFlavor(const string& name) const{
    int index = findFlavorIndex(name);
    if (index == -1){
        throw flavorNotFoundException(name)
    }
    return flavors[index];
 }

 int Inventory::getScoopsAvailable(const string& name) const{
    int index = findFlavorIndex(name);
    if (index == -1) {
        throw FlavorNotFoundException(name);
    }
    return scoopsArray[index];
 }

 osstream& operator<<(ostream& os, const Inventory& inv){
    os << "------ Inventory ------\n";
    for (int i = 0; i < inv.flavorCount; i++){
        os << inv.flavors[i]->getName()
        << " (" << inv.flavors[i]->getType() << ") -"
        << int.scoopsArray[i] << "scoops\n";
    }
    return os;
 }
