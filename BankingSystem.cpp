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


  // menu options

  if(cin.fail()) {
    cin.clear();
    cin.ignore(1000,'\n');
    cout << "Invalid, Please re-enter menu option :";
    continue;


  }
}
