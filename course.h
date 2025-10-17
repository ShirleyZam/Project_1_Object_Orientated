//Shirley Zamora
//October, 17, 2025

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


    // Getters: Encapsulation in order to safely use the attributes(private) for the methods
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
// Challenges:


// What I learned:

