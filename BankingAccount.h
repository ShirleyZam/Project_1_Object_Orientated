#include <iostream>
#include<string>
#include<vector>


using namespace std;

    class BankAccount{
        private:
//HWe have the private member variables for the data of account
            string ownerName{"First Last"}; 
            int accountNumber{};
            double balance{0.0};
            vector<string> history; //Shirley will manage this with vector

            public:
//Public data so Bankingsystems file can have access to following data
            BankAccount() {}
//Default constructor

             // Shirley: Add push_back to history to log account creation
                BankAccount(const string& ownerName, int accountNumber, double balance);
//Parameterized constructor

                //Functions: 
                    //Deposit function
                    
                void deposit(double amount){
                    //Add balance when a number is provided
                   balance += amount;

                
                   cout<< "Deposited $" << amount << endl;
                   // Person 2: Add input validation (amount > 0)
        // Shirley Add push_back to history for successful or failed deposit
        

                }


                //Shirley will add validation and history logging
                      //Withdraw function
                bool withdraw(double amount){
                    //subtract from balance if valid "if else"
                    if (amount > 0 && amount <= balance){
                        balance -= amount;

                        cout<< "Withdrew $" << amount << endl;
                        if (balance == 0.0){
                            cout<< "Balance is now zero." << endl;
                        }

                // Shirley: Add push_back to history for successful withdrawal
                        return true;
                }


                
                cout<<"Insufficient funds."<<endl;
                
        //Shirley: Add push_back to history for failed withdrawal
                    return false;
                }

              //Getbalance function
                double getBalance() const {
        
        cout << "Current Balance: $" << balance << endl;

        return balance;
    }



                // Person 2: Fully define this function to print owner name, account number, and balance
                void display() const;

                // Person 2: Fully define this function to print all entries in the history vector
                void showHistory() const;
                
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
