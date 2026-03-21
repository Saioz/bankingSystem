*/
PROJECT: Banking System with Transaction History Project
NAME: Katriel Morales
DATE: 3/21/2026
*/

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
    
    BankAccount(const string&, int, double); //Constructor
    void deposit(double amount);    // Adding to balance and gets recorded to history
    bool withdraw(double amount);   // Subracts to balance and if valid gets recorded to history
    double getBalance() const;      //Returns current balance
    void display() const;           // Printing account info
    void showHistory() const;       // Printing transaction history
};


