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

    // same names, now const
    string getName() const { return name; }
    double getPrice() const { return scoopPrice; }
    int getBucketSize() const { return bucketSize; }

    // ***make this virtual + const, same name as before***
    virtual double priceCalc(int scoops) const {
        return scoops * scoopPrice;
    }

    // ***virtual + const, same name***
    virtual string getType() const {
        return "Flavor";
    }
};
