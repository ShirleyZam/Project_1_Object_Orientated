#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <iostream>
//Darien Hector
using namespace std;

class Order{
	//variables to be used in the functions
	private:
		string flavorname;
		int scoops;
		double totalprice;
	
	//declares the functions so you are able to order
	public:
		Order();
		Order(const string& name, int s, double tp);
		string getflavorname() const;
		int getscoops() const;
		double gettotalprice() const;
		void print() const;
};
#endif