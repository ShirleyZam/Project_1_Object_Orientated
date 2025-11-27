#include <iostream>
#include <string>
using namespace std;

//General Flavor Properties:
class Flavor {
private:
    string name;
    double scoopPrice;
    int bucketSize;

public:
    Flavor() {
        name = "Unknown";
        scoopPrice = 0.0;
        bucketSize = 0;
    }

    Flavor(string n, double price, int bucket) {
        name = n;
        scoopPrice = price;
        bucketSize = bucket;
    }

    string getName() const { return name; }
    double getPrice() const { return scoopPrice; }
    int getBucketSize() const { return bucketSize; }

    // Basic price calculation
    double priceCalc(int scoops) {
        return scoops * scoopPrice;
    }

    string getType() {
        return "Flavor";
    }
};


// Regular Flavors Child Class

class RegularFlavor : public Flavor {
public:
    RegularFlavor(string n, double price, int bucket) : Flavor(n, price, bucket) {}

    string getType() {
        return "Regular";
    }
};


// Seasonal Flavor Class

class SeasonalFlavor : public Flavor {
private:
    double discount; // example: 0.20 = 20% off

public:
    SeasonalFlavor(string n, double price, int bucket, double d)
        : Flavor(n, price, bucket) {
        discount = d;
    }

    double computePrice(int scoops) {
        double base = scoops * getPrice();
        return base - (base * discount);
    }

    string getType() {
        return "Seasonal";
    }
};

// ==========================
// Operator<< OUTSIDE classes
// NO FRIEND — uses getters
// ==========================
ostream& operator<<(ostream& os, const Flavor& f) {
    os << f.getName()
       << " ($" << f.getPrice() << " per scoop)"
       << " | Bucket size: " << f.getBucketSize()
       << " | Type: " << f.getType();
    return os;
}

#endif
