#ifndef FLAVOR_H
#define FLAVOR_H
//This header file defines 

#include <iostream>
#include <string>

using namespace std;

//psrent - General
class Flavor {
private:
string name;         //flavor name
double scoopPrice;   //price per scoop 
int bucketSize;      //num of scoops in bucket

public:
//Default constructor -> "Default" placholder values 
Flavor(){
  name= "Unknown";
  scoopPrice = 0.0;
  bucketSize = 10; //default bucket size
}

//Parameterized constructor -> allows create a Flavot with:
//a specific name, a certain price scoop, a default bucket size of 10
Flavor (string n, double price,  int bucket = 10){
name = n; //Specific name
scoopPrice = Price; //certain price scoop 
bucketSize = 10; //default 10
}

//Getters - returns private data safely 
//allowing other parts of the program to safely (controlled access) read the private member variables of class
//Name, scoopPrice, bucketSize = Private -> encapsulation - cannot be accessed outside the class
string getName() const { return name;}          //return -> prevents direct modification 
double getPrice() const { return scoopPrice;}   //won't modify member variables
int getBucketSize() const { return bucketSize;} //read only 

//-Virtual- Function -> (-allows-) child class to override (-replace-) parent (The permission)
//Why?
virtual double priceCalc(int scoops) const{
  return scoops* scoopPrice; //This changes.. 
}

virtual ~Flavor() = default;
};

//Child Class - (Inherits) with own special rules
//calculates price like parent(base class) 
//Should still be treated like Flavor
class RegularFlavor : public Flavor{
public:
RegularFlavor(string n, double price, int bucket = 10)
: Flavor(n,price,10){}

dtring grtType() const override{
  return "Regular";
}
};

//Child Class - (Inherits) with own special rules
//calculates price with discount different to parent(base class) 
//Should still be treated like Flavor
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

