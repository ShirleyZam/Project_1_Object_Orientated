#ifndef STOCKREPORT_H

#define STOCKREPORT_H
 
#include "Report.h"

#include "Order.h"

#include "Stats.h"

#include <vector>

using namespace std;
 
class StockReport : public Report {

private:

    vector<Order> orders;
 
public:

    StockReport(const vector<Order>& aorders);
 
    void createReport() const override;

};
 
#endif // STOCKREPORT_H
 
