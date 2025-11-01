#include <iostream>
#include<string>
#include<vector>


using namespace std;

    class BankAccount{
        private:
            string ownerName{"First Last"};
            int accountNumber{};
            double balance{0.0};
            vector<string> history; //Person 2: Manage this with vector

            public:
            BankAccount() {}

             // Person 2: Add push_back to history to log account creation
                BankAccount(const string& ownerName, int accountNumber, double balance);
                
                void deposit(double amount){
                   balance += amount;

                   //console output for testing (person 1)
                   cout<< "Deposited $" << amount << endl;
                   // Person 2: Add input validation (amount > 0)
        // Person 2: Add push_back to history for successful or failed deposit
        

                }


                //Person 2 will add validation and history logging
                bool withdraw(double amount){
                    if (amount > 0 && amount <= balance){
                        balance -= amount;

                        cout<< "Withdrew $" << amount << endl;
                        if (balance == 0.0){
                            cout<< "Balance is now zero." << endl;
                        }

                // Person 2: Add push_back to history for successful withdrawal
                        return true;
                }


                //CONSOLDE OUTPUT FOR TESTING (PERSON 1)
                cout<<"Insufficient funds."<<endl;
                
        // Person 2: Add push_back to history for failed withdrawal
                    return false;
                }


                double getBalance() const {
        // Console output for testing (Person 1)
        cout << "Current Balance: $" << balance << endl;

        return balance;
    }



                // Person 2: Fully define this function to print owner name, account number, and balance
                void display() const;

                // Person 2: Fully define this function to print all entries in the history vector
                void showHistory() const;
                
    };

