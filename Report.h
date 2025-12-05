#ifndef REPORT_H
#define REPORT_H

#include <string>
//Darien Hector
using namespace std;

class Report{
	protected:
		string title;
	
	//creates a report and uses virtual so the class is polymorphic and usable in stock report
	public:
		Report(const string& t ="Report") : title(t){}
		virtual ~Report() = default;
		string getTitle() const{return title;}
		virtual void createReport() const =0;
};
#endif