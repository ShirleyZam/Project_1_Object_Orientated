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
        return name; //returns the private attributes safely without risking the program crashing
    }

    int getCreditHours() const {
        return creditHours;
    }

    string getLetterGrade() const {
        return letterGrade;
    }
};
// Some challenges I faced when creating this file was communicating with my group members and making sure that my file is able to function as a 
//storage for student.h this is to make sure that the input that the user inputs is able to be stored and called on later without 
//any missing information (const). 

// I learned to communicate better with fellow classmates as well as a better understanding for encapsulating private data for the program
//not to crash. 

