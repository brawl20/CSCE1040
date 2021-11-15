#include "Loan.h"
#include "Movie.h"
#include "Customer.h"
#include "LoanCollection.h"
#include "MovieCollection.h"
#include "CustomerCollection.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Menu(CustomerCollection &customerDatabase)
{
    //Variables
    long long unsigned int creditCardNum;
    int expirationDateMonth;
    int expirationDateYear;
    int userChoice;
    char userName[40];
    ofstream fout;
    ifstream fin;
    string tempHolder;
    bool inSystem = false;

    // Body
    cout << "*********Welcome to GreenBox!*********" << endl;
    cout << "Menu:" << endl;
    cout << "1) Returning Customer\n2) New Customer\n3) Exit\n";

    cin >> userChoice;
    while (userChoice != 3)
    {
        cin.ignore();
        switch (userChoice)
        {
        case 1:
            cout << "Please enter your Customer ID:\n";
            break;
        case 2:

            customerDatabase.addCustomer();
            break;

        default:
            cout << "Sorry, the choice you made was invalid. Please try again.\n";
            break;
        }
        cout << "Menu:" << endl;
        cout << "1) Returning Customer\n2) New Customer\n3) Exit\n";
        cin >> userChoice;
    }
}

int main()
{   
    CustomerCollection customerDatabase;
    Menu(customerDatabase);
    //customerDatabase.printCollectionEntries();
    return 0;
}