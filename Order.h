#include <iostream>
#include <string>


using namespace std;

class Order{
	private:
		string flavorname;
		int scoops;
		double totalprice;
		
		
		
		
		
		
	public:	
		Order();
		Order(const string& name, int s, double tp);
		
		string getflavorname() const;
		int getscoops() const;
		double gettotalprice() const;
		
		void print() const;

};
