// Author: Rejuana Afrin
// Date: 11/01/2025

#include <iostream>
#include <limits>
#include <string>
#include "bankAccount.h"  

using namespace std;

// Main part of the coding starts from here
int main() {
    cout << "=== Banking System ===" << endl;

    string accountHolder;
    int accountNumber;
    double initialDeposit;

    cout << "Enter account holder name: ";
    getline(cin, accountHolder);

    // Here input validation for account number
    while (true) {
        
        cout << "Enter account number: ";
        cin >> accountNumber;
        if (cin.fail() || accountNumber <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number.\n";
        }
        
        else break;
    
    }

    // Here I input validation for initial deposit
    while (true) {
        cout << "Enter initial deposit (>0): ";
        cin >> initialDeposit;
        if (cin.fail() || initialDeposit <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid amount. Please enter a positive number.\n";
        }
        else break;
    }

    // Here is the bankAccount object
    bankAccount account(accountHolder, accountNumber, initialDeposit);

    int choice;
    
    do {
        cout << "\nMenu:\n";
        cout << "1) Deposit\n";
        cout << "2) Withdraw\n";
        cout << "3) Show Balance\n";
        cout << "4) Show Account Info\n";
        cout << "5) Show Transaction History\n";
        cout << "6) Exit\n";
        cout << "Choose option: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error... Please enter a number between 1–6.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            double amount;
            cout << "Amount to deposit: ";
            cin >> amount;
            if (!cin.fail() && amount > 0)
                account.deposit(amount);
            else {
                cout << "Invalid amount.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            break;
        }
        case 2: {
            double amount;
            cout << "Amount to withdraw: ";
            cin >> amount;
            if (!cin.fail() && amount > 0)
                account.withdraw(amount);
            
            else {
                cout << "Invalid amount.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            break;
        }
        case 3:
            cout << "Current Balance: $" << account.getBalance() << endl;
            break;
        case 4:
            account.display();
            break;
        case 5:
            account.showHistory();
            break;
        case 6:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid menu option. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

//Reflection:
//For my part of the project, I created the main menu system that connects and it will connect the class method together. 
// I was struggeling while I was doing input validation by using cin.fail(), clear(), and ignore(). Also, I was trying so many times with the compile because it wasn't runnung. Then I realized I did some typo mistakes. 
// I was also getting stuck when I was trying to run both file at a time because it was showing error and couldn't fix the issue. Later on we fixed it by working together. 
// However, I learned how to design a menu loop that put together smoothly with a class while keeping the program easy for users.
