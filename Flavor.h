//Lucia Zuniga
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
scoopPrice = price; //certain price scoop 
bucketSize = 10; //default 10
}

//Getters - returns private data safely 
//allowing other parts of the program to safely (controlled access) read the private member variables of class
//Name, scoopPrice, bucketSize = Private -> encapsulation - cannot be accessed outside the class
string getName() const { return name; }          //return -> prevents direct modification 
double getPrice() const { return scoopPrice; }   //won't modify member variables
int getBucketSize() const { return bucketSize; } //read only 

//-Virtual- Function -> (-allows-) child class to override (-replace-) parent (The permission)
//Why?
virtual double priceCalc(int scoops) const{
  return scoops* scoopPrice; //This changes.. 
}

//Overrides and (reveals) returns string the type of flavor (object-> seasonal or regular)
 virtual string getType() const {
         return "Flavor";
 }

//Destructor - delete flavor (pointer -> derived  object) - memory safety 
    virtual ~Flavor() = default; //generate default body
 };



//Inherits from Flavor class
class RegularFlavor : public Flavor{
public:
//Constructor
//Child Class - (Inherits) with own special rules 
//calculates price like parent(base class) 
//Should still be treated like Flavor
RegularFlavor(string n, double price, int bucket = 10) //Parameters (What is needed)
: Flavor(n,price,10){} //(initializer list)

//replaces (Overrides - determines type of flavor) and checks (spelling, return type, parameters)
string getType() const override{
  return "Regular";
}
};


//Inherits from Flavor class
class SeasonalFlavor : public Flavor{
private:
double discount; //special rule (difference)
                 //Private-> we dont want discount to be accessible all the time or access to leak

public:
//constructor
//Child Class - (Inherits) with own special rules
//calculates price with discount different to parent(base class) 
//Should still be treated like Flavor
SeasonalFlavor(string n, double price, int bucket, double d) //Parameters (What is needed)
: Flavor(n, price, 10), discount(d) {} //calls base (parent) constructor
//Initializer list                     //intialize new member for this class 

//Overriden priceCalc
double priceCalc(int scoops) const override{ //replaing calculations
  double base = scoops*getPrice(); //Calculate normal price liek parent (base class)
return base - (base*discount); //(applies discount for seasonal flavor
}

//replaces (Overrides - determines type of flavor(seasonal)) and checks (spelling, return type, parameters)
string getType() const override{
  return "Seasonal";
}
};


//allows define function 
inline ostream& operator<<(ostream& os, const Flavor& f){ //return a reference and output flavor object and prevent modification of object 
  os<< f.getName()<<" ($" << f.getPrice() << " per scoop)" << " | Bucket size: " << f.getBucketSize()
    << " | Type: " << f.getType();
//we print flavors information (name, price, bucketsize)
  return os;
//return the output stream allow chaining
  
}

#endif //FLAVOR_H

