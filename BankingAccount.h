#include BankingAccount.h
#include<string>
#include<vector>


using namespace std;

    class BankAccount{
        private:
            string ownerName{"First Last"};
            int accountNumber{};
            double balance{0.0};
            vector<string> history;

            public:
            BankAccount() {}
                BankAccount(const string& ownerName, int accountNumber, double balance);
                
                void deposit(double amount);
                bool withdraw(double amount);
                double getBalance() const;
                void display() const;
                void showHistory() const;
                
    };
