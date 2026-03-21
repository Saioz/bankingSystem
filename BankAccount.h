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
    BankAccount(const string& name, int accNum, double initialDeposit) { //parameterized constructor
        ownerName = name;
        accountNumber = accNum;
        balance = initialDeposit;

        string text = to_string(initialDeposit); 
        text = text.substr(0, text.find('.') + 3); //method of saving the string with 2 decimal points into the vector

        history.push_back("Account created with initial deposit $" + text);
    }

    double getBalance() const { //getter for balance
        return balance;
    }

    void deposit(double amount) {
        balance += amount; //adds the deposit to the balance 
        
        string text = to_string(amount);
        text = text.substr(0, text.find('.') + 3); //stores with 2 decimal

        history.push_back("Deposited $" + text);//adds the deposit into the vector

        cout << fixed << setprecision(2); //prints with 2 decimal points
        cout << "Deposited $" << amount << endl;
    }

    bool withdraw(double amount) {
        if (amount > balance) { //returns false when the amount withdrawn is more than the balance
            cout << "Insufficient funds." << endl;
            return false;
        }

        balance -= amount; //decreases the withdrawn amount into balance
        
        string text = to_string(amount);
        text = text.substr(0, text.find('.') + 3);

        history.push_back("Withdrew $" + text); //stores with 2 decimal

        cout << fixed << setprecision(2); //prints with 2 decimal points
        cout << "Withdrew $" << amount << endl;

        if (balance == 0) { //if balance reaches 0 after the withdraw
            cout << "Balance is now zero." << endl;
        }

        return true;
    }


    void display() const { //displays current account information with 2 decimal points
        cout << fixed << setprecision(2);
        cout << "\n=== Account Information ===" << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }

    void showHistory() const { //displays the account history using for loop 
        cout << "\nTransaction History (" << history.size() << "):" << endl;

        for (int i = 0; i < history.size(); i++) {
            cout << "- " << history[i] << endl;
        }
    }
};

#endif