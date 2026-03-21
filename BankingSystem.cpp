/*
Name: Shadman Yusuf Kayes
Anthony Lin
Katriel Morales
Axel Pichardo Martinez
Date: 3/20/26
Description: Banking System - Midterm Project
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <limits> //used ai to see how to implement cin.ignore like how the rubric is

#include "BankAccount.h"

using namespace std;

double getPosDouble(const string& prompt) {
  //makes sure that the input from the user is a valid and POSITIVE double
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //used to properly ignore using limits
            cout << "Invalid input. Please re-enter your positive number." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// gets a positive int from cin user, then uses a while loop to make sure input is valid. 
int getPosInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please re-enter your positive integer." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

int main() {
  cout << "======== <  Banking System > ========" << endl; // print the banking system name, making it look nice
  
  string name;
  cout << "Please enter account name: ";
  getline(cin, name);  //there's no need for a cin.fail check here, since a string can be anything
  
  int accNum = getPosInt("Enter account number: ");
  double initialDeposit = getPosDouble("Enter initial deposit (>0): ");

    // Create the account
  BankAccount account(name, accNum, initialDeposit);

  
  int choice; //initializes the choice for the while loop menu. ** using case switch to make it easier than if/else 
  
  bool loop = true;//used for the while loop to break
  
  while (loop) {
  // menu options
    cout << "\nMenu:" << endl;
    cout << "1) Deposit:" << endl;
    cout << "2) Withdraw:" << endl;
    cout << "3) Show Balance:" << endl;
    cout << "4) Show Account Info:" << endl;
    cout << "5) Show Transaction History:" << endl;
    cout << "6) -Exit-" << endl;
    cout << "Choose option: ";
  
    cin >> choice;
    
  if(cin.fail()) { //checks if valid input
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid, Please re-enter menu option :";
    continue;
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  
  switch (choice) { //switch was more compact than if-else statement
        case 1: { //deposit
            double amount = getPosDouble("Amount to deposit: ");
            account.deposit(amount);
            break;
        }

        case 2: {//withdraw
            double amount = getPosDouble("Amount to withdraw: ");
            account.withdraw(amount);
            break;
        }

        case 3://check Balance
            cout << fixed << setprecision(2);
            cout << "Balance: $" << account.getBalance() << endl;
            break;

        case 4://display
            account.display();
            break;

        case 5://History
            account.showHistory();
            break;

        case 6://exit
            cout << "Goodbye!" << endl;
            loop = false;
            break;

        default:
            cout << "Please select a valid menu option!" << endl;
        }
    }
    
    return 0;
}

/*
Shadman Yusuf Kayes's reflection:
For this project, I mainly worked on the header file with Axel. One part that I got issues from was trying to set the decimal point to 2 inside a string
for the vector. This was a problem because of how setprecision only works when outputting and cannot be used for storing. I found a work around by using using
substr and find, where I would get the substring of the amount and use .find('.') + 3 for the length. This helped me control how the string was stored in the 
transaction history and keep it consistent with two decimal places. Finding this out helped me understand the difference between formatting output and actually 
modifying stored data.







*/
