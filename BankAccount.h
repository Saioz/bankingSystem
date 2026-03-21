#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;



class BankAccount {
    private:                    // Private Encapsualtion - These members are hidden from the outside acces
    
    string ownerName;           //Stores string of the account holder
    int accountNumber;          // Stores int for the unique ID for the holder's bankaccount
    double balance;             // Stores the current money amount (uses decimal point values)
    vector <string> history;    // A dynamic list to save every successful transaction message
    
    

    
    public:
    
    BankAccount(const string& name, int accNum, double intitialDeposit) { //Constructor
        ownerName = name;
        accountNumber = accNum;
        balance = intitialDeposit;

        cout << fixed << setprecision(2);
        string msg = "Account created with intitial deposit $" + to_string(balance);
        history.push_back(msg);
    }
    void deposit(double amount);    // Adding to balance and gets recorded to history
    bool withdraw(double amount);   // Subracts to balance and if valid gets recorded to history
    double getBalance() const { //Returns current balance
        return balance;
    }
    
void display() const { // Printing account info 
    cout << fixed << setprecision(2);
    cout << "Owner Name: " << ownerName <<endl;
    cout << "Account Number: " << acountNumber <<endl;
    cout << "Balance: $" <<balance <<endl;
}

    void showHistory() const;       // Printing transaction history
};

#endif

