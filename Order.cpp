#include "Order.h"
#include <iostream>
#include <string>

Order::Order() : flavorname(" "), scoops(0), totalprice(0.0){}

Order::Order(const string& name, int scoop, double price) : flavorname(name), scoops(scoop), totalprice(price){}

string Order::getflavorname() const{return flavorname;}
int Order::getscoops() const{return scoops;}
double Order::gettotalprice() const{return totalprice;}

void Order::print() const {
	cout << "Flavor: " << flavorname << "\namount of scoops:" << scoops << "\ntotal price" << totalprice;
	
}
}