#include BankingSystem.cpp
#include<iostream>
#include<string>
#include <sstream>
#include<vector>
#include<iomanip>

using namespace std;

    class BankAccout{
        Private:
            string ownerName{"First Last"};
            int accountNumber{};
            double balance{0.0};
            vector<string> history;

            Public:
            BankAccount() {}
                BankAccount(const string& ownerName, int accountNumber, double balance);
                
                void deposit(double amount);
                bool withdraw(double amount);
                double getBalance() const;
                void display() const;
                void showHistory() const;
                
    };
