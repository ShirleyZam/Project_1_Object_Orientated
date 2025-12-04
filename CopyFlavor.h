#ifndef FLAVOR_H

 #define FLAVOR_H
 
#include <iostream>

 #include <string>

 using namespace std;
 
class Flavor {

 private:

     string name;

     double scoopPrice;

     int bucketSize;   // always 10 in our logic
 
public:

     Flavor() {

         name = "Unknown";

         scoopPrice = 0.0;

         bucketSize = 10;   // default bucket size

     }
 
    // We keep bucket as a parameter, but default to 10

     Flavor(string n, double price, int bucket = 10) {

         name = n;

         scoopPrice = price;

         bucketSize = 10;   // ignore the passed bucket and force 10

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
 
    virtual ~Flavor() = default;

 };
 
 
// ========================

 // RegularFlavor

 // ========================

 class RegularFlavor : public Flavor {

 public:

     RegularFlavor(string n, double price, int bucket = 10)

         : Flavor(n, price, 10) {}  // always passes 10
 
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

         : Flavor(n, price, 10), discount(d) {}  // bucket forced to 10
 
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
