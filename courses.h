#include <iostream>
#include <string>
#include <vector>
#include <limits>


using namespace std;



class Course{
    private: 
    vector<string>courses;
    vector<int>creditHours; 
    vector<string>letterGrade;

    public:
    ~Course(){

    }

    Course(){

    }

    Course(vector<string>Courses,vector<int>CreditHours,vector<string>LetterGrade){
        courses = Courses;
        creditHours = CreditHours;
        letterGrade = LetterGrade;
    }

    void getCourses(int &N){
        cout << "How many courses do you have? \n"; 
        cin >> N;
        cin.ignore();

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cerr << "Invalid. Please enter a integer \n";
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
            courses.push_back(course);
         }
    }   

    void getCreditHours(int N){
        cout << "How many credits is each course \n";
    
        for (int i = 0; i < N; i++){
            int hours;
            while (true){ 
                cout << "Credit hours for " << courses[i] << ": ";
                cin >> hours;

                if (cin.fail() || hours <= 0) {
                    cin.clear(); // clear failbit
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cerr << "Invalid input. Hours must be a positive number.\n";
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


    void getLetterGrade(int N) {
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

