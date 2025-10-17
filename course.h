#include <iostream> 
#include <string>

using namespace std;

class Course {
private:
    string name; // gets the name of the courses
    int creditHours; // gets the credit of the courses 
    string letterGrade; // gets the letter grade of the courses 

public:
    // Constructor 
    Course(string courseName, int credits, string grade) {
    name = courseName;
    creditHours = credits;
    letterGrade = grade;
}


    // Getters
    string getName() const {
        return name;
    }

    int getCreditHours() const {
        return creditHours;
    }

    string getLetterGrade() const {
        return letterGrade;
    }
};
