#ifndef STOCKREPORT_H
#define STOCKREPORT_H
#include "Report.h"
#include "Order.h"
#include "Stats.h"
#include <vector>
//Darien Hector
using namespace std;

class StockReport : public Report{
	private:
		vector<Order> orders;
	
	//creates the vector to store data for the report and display it	
	public:
		StockReport(const vector<Order>& aorders);
		
		void createReport() const override;
};
#endif 