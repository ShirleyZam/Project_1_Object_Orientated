#ifndef REPORT_H

#define REPORT_H
 
#include <string>

using namespace std;
 
class Report {

protected:

    string title;
 
public:

    Report(const string& t = "Report") : title(t) {}

    virtual ~Report() = default;
 
    string getTitle() const { return title; }
 
    virtual void createReport() const = 0;

};
 
#endif // REPORT_H
 
