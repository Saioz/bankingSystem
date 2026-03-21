#ifndef BANKACCOUNT_H // best practice for .h files to stop it from running twice
#define BANKACCOUNT_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class BankAccount {
private:// Private Encapsualtion - These members are hidden from the outside access
    string ownerName;//Stores string of the account holder
    int accountNumber; //stores int for account number
    double balance; //stores initialDeposit and current balance as a double
    vector<string> history;//a vector to keep track of past transactions

public:
    BankAccount(const string& name, int accNum, double initialDeposit) {
        ownerName = name;
        accountNumber = accNum;
        balance = initialDeposit;
        string text = to_string(initialDeposit);
        text = text.substr(0, text.find('.') + 3);

        history.push_back("Account created with initial deposit $" + text);
    }

    void deposit(double amount) {
        balance += amount;
        
        string text = to_string(amount);
        text = text.substr(0, text.find('.') + 3); //stores with 2 decimal

        history.push_back("Deposited $" + text);

        cout << fixed << setprecision(2);
        cout << "Deposited $" << amount << endl;
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds." << endl;
            return false;
        }

        balance -= amount;
        
        string text = to_string(amount);
        text = text.substr(0, text.find('.') + 3);

        history.push_back("Withdrew $" + text);

        cout << fixed << setprecision(2);
        cout << "Withdrew $" << amount << endl;

        if (balance == 0) {
            cout << "Balance is now zero." << endl;
        }

        return true;
    }

    double getBalance() const {
        return balance;
    }

    void display() const {
        cout << fixed << setprecision(2);
        cout << "\n=== Account Information ===" << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }

    void showHistory() const {
        cout << "\nTransaction History (" << history.size() << "):" << endl;

        for (int i = 0; i < history.size(); i++) {
            cout << "- " << history[i] << endl;
        }
    }
};

#endif