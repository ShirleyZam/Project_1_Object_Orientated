#include <iostream>
#include <string>
#include <vector>
#include <limits>


using namespace std;



class CourseSchedule{
    private: 
    vector<string>courses;
    vector<int>creditHours; 
    vector<string>letterGrade;

    public:
    ~CourseSchedule(){

    }

    CourseSchedule(){

    }

    CourseSchedule(vector<string>Courses,vector<int>CreditHours,vector<string>LetterGrade){
        courses = Courses;
        creditHours = CreditHours;
        letterGrade = LetterGrade;
    }

    void GetCourses(int &N){
        cout << "How many courses do you have? \n"; 
        cin >> N;
        

        if (cin.fail()){
            cerr << "Invalid. Please enter a integer \n";
            cin.clear();
            return;
        } 
        
        if (N>10){
        cerr<<"Error you cannot have more than 10 classes";
        return;
        }
        
        cout << "What courses do you have? \n";
        for (int i = 0; i < N; i++){
            string course; 
            cout << "Course " << i + 1 << ": ";
            getline(cin,course);
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            courses.push_back(course);
    }
};

    void GetCreditHours(int N) {
        cout << "How many credits is each course \n";
    
        for (int i = 0; i < N; i++) {
            int hours;
            while (true) { 
                cout << "Credit hours for " << courses[i] << ": ";
                cin >> hours;

                if (cin.fail() || hours <= 0) {
                    cerr << "Invalid input. Hours must be a positive number.\n";
                    cin.clear(); // clear failbit
                } else {
                    creditHours.push_back(hours);
                    break; 
                }
            }
        }

    }

    bool isValidGrade(const string& g) {
        vector<string> validGrades = {"A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+","D","D-", "F"};

        for (string grade : validGrades) {
            if (g == grade) {
                return true; 
            }
        }
        return false; 
    }


    void GetLetterGrade(int N) {
        cout << "What letter grade did you get for each course? "<< endl;
    
        for(int i = 0; i < N; i++){
            string letter_grade;
             
            do{
                cout<<"Letter Grade "<< courses[i] << ": ";
                cin >> letter_grade;
                
                if(isValidGrade(letter_grade)){
                    letterGrade.push_back(letter_grade);
                    break;
                }else{
                    cerr << "Ivalid grade.\n";
                    }
                } while(true);
        }
    }


};

