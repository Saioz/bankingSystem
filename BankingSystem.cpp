// Name: ------------------
// Date: 3/20/26
// Description: Banking System - Midterm Project

#include <iostream>
#include <string>
#include <limits>
#include "BankAccount.h"

using namespace std;



int main() {
  cout << "======== <  Banking System > ========" << endl;
  // print the banking system name, making it look nice!


  string name;
  cout << "Please enter account name: ";
  getline(cin, name);
  //there's no need for a cin.fail check here, since a string can be anything

  
  int choice;
  //initializes the choice for the while loop menu. ** using case switch to make it easier than if/else 
  while (true) {
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
    //stores the choice 
  if(cin.fail()) {
    cin.clear();
    cin.ignore(1000,'\n');
    cout << "Invalid, Please re-enter menu option :";
    continue;
  }
  cin.ignore(1000, '\n');

  
  switch (choice) {
    case 1: 
    cout << "case1"<< endl;
    break;

    case 2: 
    cout << "case2"<< endl;
    break;

    case 3:
    cout << "case3"<< endl;
    break;

    case 4:
    cout << "case4"<< endl;
    break;

    case 5:
    cout << "case5"<< endl;
    break;

    case 6: 
    cout << "case6" << endl;
    break;

    default: 
    cout << "this is default, please select a valid menu option!" << endl;
    break;
  }

  }

}
