/*
Name: 
Anthony Lin
Shadman Yusuf Kayes
Katriel Morales
Axel Pichardo Martinez
Date: 3/20/26
Description: Banking System - Midterm Project
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <limits> //used ai to ask how to implement cin.ignore like how the rubric recommends

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


//Shadman Yusuf Kayes's reflection:

/*
For this project, I mainly worked on the header file with Axel. One part that I got issues from was trying to set the decimal point to 2 inside a string
for the vector. This was a problem because of how setprecision only works when outputting and cannot be used for storing. I found a work around by using using
substr and find, where I would get the substring of the amount and use .find('.') + 3 for the length. This helped me control how the string was stored in the 
transaction history and keep it consistent with two decimal places. Finding this out helped me understand the difference between formatting output and actually 
modifying stored data.

*/

//Anthony Lin's reflection:

/*

In this project, I worked mainly on the main file alongside Katriel. Something that was tricky and gave me a bunch of issues was 
trying to set up the initial menu screen. When I was trying to set up the while loop, I made a switch case that was outside of the loop
this took a while for me to figure out and was something I overlooked. I learned that getline doesn't need cin.fail() which should've been obvious.
Since getline just retrieves whatever is inserted. In this case, it stores a string, which can be numbers, doubles, literally anything. Additionally, I learned
about what continue does, in this case, continue just returns the code back into the while loop. 

*/

// Katriel Morales's Reflection:

/*
While structuring the Bank System Transaction History App, I was able to initialize the BankAccount.h class 
and made sure the logic in our implementation file was consistent. I also collaborated closely with my groupmate Axel and 
checked that his member functions were implemented correctly to ensure the code would run smoothly. 
This project helped me understand the importance of peer review and the benefits of using switch case statements, 
as they made the menu logic much simpler and neater to read and use for this project.

*/
