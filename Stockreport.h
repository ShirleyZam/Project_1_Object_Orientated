#ifndef STOCKREPORT_H
#define STOCKREPORT_H

#include "Report.h"
#include "Order.h"
#include <vector>
#include <string>

class StockReport : public Report{
	private:
		vector<order> Orders;
		
	public:
		StockReport(const vector<order>& Orders);
		void createReport() const;
	
};
#endif