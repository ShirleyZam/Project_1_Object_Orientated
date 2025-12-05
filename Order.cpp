#include "Order.h"

#include <iostream>
//Darien Hector
using namespace std;
//default constructor withbase values
Order::Order() : flavorname(" "), scoops(0), totalprice(0.0){}

Order::Order(const string& name, int s , double tp) :flavorname(name), scoops(s), totalprice(tp){}

//uses getter functions to return the values assigned to them
string Order::getflavorname() const{return flavorname;}
int Order::getscoops() const{return scoops;}
double Order::gettotalprice() const{return totalprice;}
//prints the users order using the function from report.h
void Order::print() const{
	cout<<"Flavor: " <<flavorname <<"\nAmount of scoops: " <<scoops <<"\ntotal price: "<<totalprice<<"\n";
}