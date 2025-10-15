#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
    //students data which is why its private
    private:  
    string fullName{"First Last"};
    vector<string> courseNames; // Fixed: should be courseNames, not courseName

    public:
    Student(){}
    //default constructor - creating a student with deault values "First Last" and no courses

    Student (string name) {
        fullName = name;
    }
    //Creates a student and sets their name 

    Student(const Student& other){
        fullName = other.fullName;
        courseNames = other.courseNames;
    }
    //creates a new student as a copy of another student data

    void addCourse(string course){
        courseNames.push_back(course);
    }
    //Adds a course name to the students list of courses

    void printInfo() const{
        cout << "Courses: ";
        for (const string& course : courseNames) {
            cout << course << " ";
        }
        cout << endl;
    }
    //Prints the students name and list of courses they are enrolled in
};