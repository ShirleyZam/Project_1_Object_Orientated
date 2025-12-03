#ifndef STOCKREPORT_H
#define STOCKREPORT_H

#include "Report.h"
#include "Order.h"
#include <vector>
#include <string>

class StockReport : public Report{
	private:
		vector<order> orders;
		
	public:
		StockReport(const vector<order>& aorders);
		void createReport() const;
	
};

#endif
