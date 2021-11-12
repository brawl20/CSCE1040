#include "Loan.h"
#include "Movie.h"
#include "Customer.h"
#include "LoanCollection.h"
#include "MovieCollection.h"
#include "CustomerCollection.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void Menu()
{
    //Variables
    int userChoice;
    char userName[40];

    // Body
    cout << "*********Welcome to GreenBox!*********" << endl;
    cout << "Menu:" << endl;
    cout << "1) Returning Customer\n2) New Customer\n3) Exit\n";

    cin >> userChoice;
    while (userChoice != 3)
    {
        switch (userChoice)
        {
        case 1:
            cout << "Please enter your Customer ID:\n";
            break;
        case 2:
            cout << "Please enter your name:\n";
            cin.ignore();
            cin.getline(userName, 40);
            break;
        default:
            cout << "Sorry, the choice you made was invalid. Please try again.\n";
            break;
        }
        cin >> userChoice;
    }
}

int main()
{
    Menu();
    return 0;
}