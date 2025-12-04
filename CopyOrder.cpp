#include "Order.h"

#include <iostream>
 
using namespace std;
 
Order::Order()

    : flavorname(" "), scoops(0), totalprice(0.0) {}
 
Order::Order(const string& name, int s, double tp)

    : flavorname(name), scoops(s), totalprice(tp) {}
 
string Order::getflavorname() const { return flavorname; }

int Order::getscoops() const { return scoops; }

double Order::gettotalprice() const { return totalprice; }
 
void Order::print() const {

    cout << "Flavor: " << flavorname
<< "\nAmount of scoops: " << scoops
<< "\nTotal price: " << totalprice << "\n";

}
 
