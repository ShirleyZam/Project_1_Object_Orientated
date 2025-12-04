#ifndef FLAVOR_H
#define FLAVOR_H

#include <iostream>
#include <string>
using namespace std;

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

    // Getters (must be const)
    string getName() const { return name; }
    double getPrice() const { return scoopPrice; }
    int getBucketSize() const { return bucketSize; }

    // Base behavior (polymorphic)
    virtual double priceCalc(int scoops) const {
        return scoops * scoopPrice;
    }

    virtual string getType() const {
        return "Flavor";
    }
};


// ========================
// RegularFlavor
// ========================
class RegularFlavor : public Flavor {
public:
    RegularFlavor(string n, double price, int bucket)
        : Flavor(n, price, bucket) {}

    string getType() const override {
        return "Regular";
    }
};


// ========================
// SeasonalFlavor
// ========================
class SeasonalFlavor : public Flavor {
private:
    double discount; // example: 0.20 = 20%

public:
    SeasonalFlavor(string n, double price, int bucket, double d)
        : Flavor(n, price, bucket), discount(d) {}

    // seasonal pricing uses discount
    double priceCalc(int scoops) const override {
        double base = scoops * getPrice();
        return base - (base * discount);
    }

    string getType() const override {
        return "Seasonal";
    }
};

// ========================
// Operator<<
// ========================
inline ostream& operator<<(ostream& os, const Flavor& f) {
    os << f.getName()
       << " ($" << f.getPrice() << " per scoop)"
       << " | Bucket size: " << f.getBucketSize()
       << " | Type: " << f.getType();
    return os;
}

#endif // FLAVOR_H
