//Rejuana Afrin
//10/17/2025
#include <limits> 
#include <iostream>
#include <iomanip>     
#include <string>
#include "student.h"

using namespace std;

void displayCinFlags() {
    cout << "\n[ CIN STATE FLAGS ]\n";
    cout << "good(): " << cin.good() << "\n";
    cout << "fail(): " << cin.fail() << "\n";
    cout << "bad():  " << cin.bad() << "\n";
    cout << "eof():  " << cin.eof() << "\n";
    cout << "--------------------\n\n";
}

// Resets cin if there's an error and clears the buffer
void clearCinError() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "[ Oops! That's not correct. Please try again. ]\n";
    displayCinFlags();
}

int main() {
    string name;
    int numCourses;

    cout << "Enter student's full name: ";
    getline(cin, name);

    Student student(name);

    cout << "How many courses did " << name << " take? (1–10): ";
    cin >> numCourses;
    displayCinFlags(); // it shows what cin looks like after reading

    // it will keep asking until input is valid
    while (cin.fail() || numCourses < 1 || numCourses > 10) {
        cerr << " That's invalid input. Please enter a number between 1 and 10: ";
        clearCinError();
        cin >> numCourses;
        displayCinFlags();
    }
    clearCinError(); // Clean up before using getline again

    for (int i = 0; i < numCourses; ++i) {
        string courseName, letterGrade;
        int creditHours;

        cout << "\nCourse " << i + 1 << " name: ";
        getline(cin, courseName);

        cout << "Credit hours for " << courseName << ": ";
        cin >> creditHours;
        displayCinFlags();

        while (cin.fail() || creditHours < 0) {
            cerr << "That's invalid input. Please enter a number between 1 and 10: ";
            clearCinError();
            cin >> creditHours;
            displayCinFlags();
        }
        clearCinError();

        cout << "Letter grade for " << courseName << ": ";
        cin >> letterGrade;
        clearCinError();

        Course course(courseName, creditHours, letterGrade);
        student.addCourse(course);
    }


    // for print transcript I mostly used setw 
    cout << "\n=============== Student Grade Report ===============\n";
    cout << "Student: " << student.getName() << "\n\n";

    cout << left << setw(20) << "Course"
         << setw(10) << "Credits"
         << setw(12) << "GradePts"
         << setw(12) << "TotalPts" << "\n";
    cout << setfill('-') << setw(56) << "" << setfill(' ') << "\n";

    double totalPoints = 0;
    int totalCredits = 0;

    for (const Course& c : student.getCourses()) {
        double gp = student.getGradePoint(c.getLetterGrade());
        double tp = gp * c.getCreditHours();

        cout << left << setw(20) << c.getName()
             << setw(10) << c.getCreditHours()
             << setw(12) << fixed << setprecision(2) << gp
             << setw(12) << fixed << setprecision(2) << tp << "\n";

        totalPoints += tp;
        totalCredits += c.getCreditHours();
    }

    double gpa = student.calculateGPA();


    cout << "\n" << left << setw(20) << "Total Credits:" << totalCredits << "\n";
    cout << left << setw(20) << "Total Points:" << fixed << setprecision(2) << totalPoints << "\n";
    cout << left << setw(20) << "Semester GPA:" << fixed << setprecision(2) << gpa << "\n";


    if (gpa >= 3.7)
        cout << left << setw(20) << "Standing:" << "Dean's List\n";
    else if (gpa >= 2.0)
        cout << left << setw(20) << "Standing:" << "Good Standing\n";
    else
        cout << left << setw(20) << "Standing:" << "Probation\n";

    return 0;
}
// Reflection:
// I faced some challanges while I was writing and researching this code. I found or faced some hard parts of this project was handling user input properly. 
// I had to make sure the program didn’t break when someone typed in something unexpected. 
// When I was using cin flags and clearing errors I had to check so many times by running my code and error to fully understand why it's noy working. 
// I also found challenging to keep the input flow smooth, mostly when switching between getline and cin. 
// Another challenge was keeping the code organized while working with multiple files with my partners like the student and course classes.

// I learned importance of input validation in real life program. 
// I really learned using while loops to keep asking for correct input until it’s valid. 
// I also became more comfortable using functions to check and reset cin states. 
// Most importantly, this project helped me better understand how classes can work together to keep the code clean and if I use setw instead of putting some gaps that will save a lot of time. 
// However, it made me realized that how writing code not only works but also handles errors nicely and stays organized.
