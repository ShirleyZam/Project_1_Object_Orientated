#include "courses.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
    //students data which is why its private
    private:  
    string fullName{"First Last"};
    vector<course> courses; // Fixed: should be courseNames, not courseName

    public:
    Student(){}
    //default constructor - creating a student with deault values "First Last" and no courses

    Student (string name) {
        fullName = name;
    }
    //Creates a student and sets their name 

    Student(const Student& other){
        fullName = other.fullName;
        courses = other.courses;
    }
    //creates a new student as a copy of another student data

    void addCourse(const Course& course){
        courses.push_back(course);
    }
    //Adds a course name to the students list of courses

    void printInfo() const{
        cout << "Courses: ";
        for (const Course& course : courses) {
            cout << course.getName() << " ";
        }
        cout << endl;
    }
    //Prints the students name and list of courses they are enrolled in

    double getGradePoint(const string& grade) const {
        if (grade == "A") return 4.0;
        else if (grade == "A-") return 3.7;
        else if (grade == "B+") return 3.3;
        else if (grade == "B") return 3.0;
        else if (grade == "B-") return 2.7;
        else if (grade == "C+") return 2.3;
        else if (grade == "C") return 2.0;
        else if (grade == "C-") return 1.7;
        else if (grade == "D+") return 1.3;
        else if (grade == "D") return 1.0;
        else if (grade == "D-") return 0.7;
        else if (grade == "F") return 0.0;
        else return -1; // Invalid grade
        
    }

    double calculateGPA() const {
        double totalPoints = 0;
        int totalCredits = 0;
        for (const Course& course : courses) {
            double gradePoint = getGradePoint(course.getLetterGrade());
            if (gradePoint >= 0) { // Valid grade
                totalPoints += gradePoint * course.getCreditHours();
                totalCredits += course.getCreditHours();
            }
        }
        if (totalCredits == 0) return 0.0; // Avoid division by zero
        return totalPoints / totalCredits;
    }



};
