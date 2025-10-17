// Lucia Zuniga
// 10-17-2025

#include "courses.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
    //students data which is why its private
    private:  
    string fullName{"First Last"};
    vector<Course> courses; 

    public:
    Student(){}
    //default constructor - creating a student with deault values "First Last" and no courses

    Student (string name) {
        fullName = name;
    }
    
    string getName() const {
        return fullName;
    }

    vector<Course> getCourses() const {
        return courses;
    }

    Student(const Student& other){
        fullName = other.fullName;
        courses = other.courses;
    }
    

    void addCourse(const Course& course){
        courses.push_back(course);
    }
    //Adds a course name to the students list of courses


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


// Reflection -
// Challenges:
// One of the biggest challenges I faced during the project was working with loops especially choosing the right type of loop and 
// making sure I included all the necessary information for the student class to ensure its does the proper job. 
// I also had to be careful that my code didn’t interfere with other files in the project 
// meaning that I had to have a lot of communication with my group was really important to avoid clashes or confusion.

// What I learned:
// I got a lot more comfortable using loops and understanding how they work in different situations. 
//Also because I feel like its been a while since I last used loops.
//I also learned how important it is to include the right components in a class like constructors 
//so everything interconnects properly. 
//This project gave me a chance to practice  clean organization,  consistent code and the thought process about 
//how each part fits into the bigger task efficiently.
