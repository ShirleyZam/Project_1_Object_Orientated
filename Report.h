#ifndef REPORT_H
#define REPORT_H

#include <string>

class Report{
	private:
		string title;
		
	public:
		Report(const string& t = "Report of sales") title(t) {}
		string gettitle(){return title;}
};
#endif