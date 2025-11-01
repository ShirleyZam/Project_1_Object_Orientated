//Author: Rejuana Afrin
//Date: 11/01/2025

#include <iostream>
#include <limits>
#include "bankAccount.h"  


using namespace std;

// Main part of the coding starts from here
int main() {
    cout << "=== Banking System ===" << endl;

    string accoutHolder;
    int accountNumber;
    double initialDeposit;

    cout << "Enter accoutHolder name: ";
    getline(cin, accoutHolder);

    // Input validation for account number
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

    // Input validation for initial deposit
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

    // Create account using class from BankAccount.h
    bankAccount account(owner, accountNumber, initialDeposit);

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

        // Stream validation
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1–6.\n";
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
