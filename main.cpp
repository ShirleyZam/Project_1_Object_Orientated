#include "courses.h"
#include "student.h"

int main() {
    // Test if CourseSchedule class is accessible
    CourseSchedule testCourseSchedule;
    testCourseSchedule.displayInfo(); // Make sure displayInfo() exists

    // Test if Student class or function is accessible
    Student testStudent;
    testStudent.printInfo(); // Use printInfo() if displayInfo() doesn't exist

    CourseSchedule cs2;
    int N;
    cs2.GetCourses(N);
    cs2.GetCreditHours(N);
    cs2.GetLetterGrade(N);
    cs2.displayInfo();

    return 0;
}