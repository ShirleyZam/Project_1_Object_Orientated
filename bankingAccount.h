#include <iostream>
#include<string>
#include<vector>


using namespace std;

    class BankAccount{
        private:
//We have the private member variables for the data of account
            string ownerName{"First Last"}; 
            int accountNumber{};
            double balance{0.0};
            vector<string> history; //Shirley will manage this with vector

            public:
//Public data so Bankingsystems file can have access to following data
            BankAccount() {}
//Default constructor

                 BankAccount(const string& OwnerName, int AccountNumber, double Balance){
                    //Shirley : Encapsulation using the parametized constructor to access the private Data Members
                    ownerName = OwnerName;
                    accountNumber = AccountNumber;
                    balance = Balance;
                    //Shirley: Vectors first members will start out with the name and initial balance
                    history.push_back("Account created for: " + ownerName + "Balance: $" + to_string(balance));

                }
//Parameterized constructor

                //Functions: 
                    //Deposit function
                    
                void deposit(double amount){
                    //Add balance when a number is provided
                    //Shirley: Constructed if statement for when the amount it less than 0 
                    if(amount > 0){
                        balance += amount;
                        cout<< "Deposited $" << amount << endl;
                    //Shirley: added successful deposit action to the history vector for later access
                        history.push_back("Desposited $" + to_string(amount));
                    }else{
                        cout << "Error, amount has to be greater than 0";
                    
                    }
                
                }


                
                      //Withdraw function
                bool withdraw(double amount){
                    //subtract from balance if valid "if else"
                    if (amount > 0 && amount <= balance){
                        balance -= amount;
                        cout<< "Withdrew $" << amount << endl;
                        // Shirley: Add push_back to history for successful withdrawal
                        history.push_back("Withdrew $" + to_string(amount));
                        if (balance == 0.0){
                            cout<< "Balance is now zero." << endl;
                        }

                        return true;
                }
                
                cout<<"Insufficient funds."<<endl;
                
                    return false;
                }

              //Getbalance function
                double getBalance() const {
        
                cout << "Current Balance: $" << balance << endl;

                 return balance;
                
                }



                // Shirley: Constructed display function to show the users account infromation
                void display() const{
                    cout << "\n=== Account Info ===\n";
                    cout << "Owners Name: " << ownerName << endl; 
                    cout << "Account Number: " << accountNumber <<endl;
                    cout << "Balance: $"<< balance <<endl;
                }

                // Shirley: Displayed successful transactions the user makes with an if statement
                //if its empty there is nothing to display, if there are members display using for loop
                void showHistory() const{
                    cout <<"\n Transaction Histroy: \n";
                    if (history.empty()){
                        cout << "No recent Transactions \n";
                    }else{
                        for (int i = 0; i < history.size(); i++){
                            cout << "- " << history[i]<<endl;
                        }
                    }

                }
                
    };



//Lucia Zuniga
//11-1-25
//Reflection-
//Challenges: I think that one challenge our team faced during this project was being able to coordinate our schedules. With different boundaries and schedules  
//it was difficult to find a moment to get on a call together to get the project over with. Because of that I felt like we had to be more active when it came 
//to written communication through Instagram and comments within the code. As well as making sure that each part of the project was fairly distributed. 
//
//Solution: In order to help prevent miscommunication, I added comments directly to the code I input to help guide Shirley since we were working in the same file. 
//Eventhough we couldn't connect live, this helped us stay on the same page. Another step taken was updating my teamates through text explpaining what tasks I completed for the day.
//
//What I Learned: Something that I relearned was thoroughly understanding the process of how constructors work, especially the importance of a parameterized constructor. At first 
//I forgot to include it but once it was revised I made sure I fully completed it so it wouldn't confuse my teamate. I also got to remember the usage of pass by
//reference by using "&" making sure that the data was passed. 

//Shirley Zamora
//11/1/25
//Some Challeneges I faced during this project was communication as we all had worked on this at different times and it was hard to distribute 
//who would complete which part of the code. Another challenge was sharing this file with another person when the last 
//project I was able to have a complete file to myself. The solution was to communicate through instagram with chat with my group members on who will 
//be doing what. With the file sharing Lucia  put comments to help me understand what she added, which guided me to complete my part of the code (filling out the missing parts) 
//I also updated her and my other group member through text what I had completed. Some things that I learned 
//thoughout this project was practicing the concatenation of strings while also applying it to a vector, it was 
//at first tricky because the vector used to store the history was initialized as a string, so I had to 
//change the integer to a string using to_string. 
//
