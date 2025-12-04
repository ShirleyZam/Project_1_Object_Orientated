#ifndef FLAVOR_H
#define FLAVOR_H
//This header file defines 

#include <iostream>
#include <string>

using namespace std;

class Flavor {
private:
string name;
double scoopPrice;
int bucketSize;

public:
Flavor(){
  name= "Unknown";
  scoopPrice = 0.0;
  bucketSize = 10;
}

Flavor (String n, double price,  int bucket = 10){
name = n;
scoopPrice = Price;
bucketSize = 10;
}

string getName() const { return name;}
double getPrice() const { return scoopPrice;}
int getBucketSize() const { return bucketSize;}

virtual double priceCalc(int scoops) const{
  return scoops* scoopPrice;
}

virtual ~Flavor() = default;
};

class RegularFlavor : public Flavor{
public:
RegularFlavor(string n, double price, int bucket = 10)
: Flavor(n,price,10){}

dtring grtType() const override{
  return "Regular";
}
};

class SeasonalFlavor : public Flavor{
private:
double discount;

public:
seasonalFlavor(string n, double price, int bucket, double d)
: Flavor(n, price, 10), discount(d) {}

double priceCalc(int scoops) const override{
  double base = scoops*getPrice();
return base - (base*discount);
}

string getType() const override{
  return "Seasonal";
}
};

inline ostream& operator<<(ostream& os, const Flavor& f){
  os<< f.getName()<<" ($" << f.getPrice() << " per scoop)" << " | Bucket size: " << f.getBucketSize()
    << " | Type: " << f.getType();

  return os;
}

#endif //FLAVOR_H

