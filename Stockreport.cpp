//Darien Hector
#include "Stockreport.h"
#include <iostream>

using namespace std;

StockReport::StockReport(const vector<Order>& aorders) 
: Report("stock report"), orders(aorders) {}

void StockReport::createReport() const{
	cout << title << "\n";
	
	string flavors[10];
	int count[10];
	int eaten =0;
	int counter = -1;
	
	//gets the flavor name and amount of scoops and assigns it to the vector to be stored
	for(size_t i=0; i<orders.size(); i++){
		string flavor = orders[i].getflavorname();
		int scoop = orders[i].getscoops();
			for(int j=0; j<eaten; j++){
				if(flavors[j]==flavor){
					counter=j;
					break;
				}
			} 
			if(counter == -1){
				flavors[eaten] = flavor;
				count[eaten] = scoop;
				eaten++;
			} else{count[counter]+=scoop;}
	}
	for(int i=0; i<eaten; i++){
		cout <<flavors[i]<<" " <<count[i] <<"scoops sold" <<endl;
	}
	

}
