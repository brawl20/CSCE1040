/*
	Author:			Micheal Landsbaum (MichealLandsbaum@my.unt.edu)
	Date:			11/16/2021
	Course:         CSCE1040
	Assignment:     Homework 3
*/

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

bool checkIDNumber(CustomerCollection &customerDatabase, int userID, int &customerIndex)
{
    ifstream fin;
    string tempHolder;
    Movie tempMovie;
    int tempInt;
    bool returnValue = false;

    fin.open("GreenBox-Data.txt"); 

    while(!fin.eof())
    {
        getline(fin,tempHolder);
        if(tempHolder == "Customer ID:")
        {
            ++customerIndex;
            getline(fin,tempHolder);
            tempInt = stoi(tempHolder);
            if (tempInt == userID)
            {
                returnValue = true;
                return returnValue;
            }
        }
    }
    return returnValue;
}


void Menu(CustomerCollection &customerDatabase)
{
    //Variables
    long long unsigned int creditCardNum;
    int expirationDateMonth;
    int expirationDateYear;
    int userChoice;
    int customerID;
    int customerIndex = -1;
    //char userName[40];
    ofstream fout;
    ifstream fin;
    string tempHolder;
    bool inSystem = false;

    // Body
    cout << "*********Welcome to GreenBox!*********" << endl;
    cout << "\nMenu:" << endl;
    cout << "1) Returning Customer\n2) New Customer\n3) Exit\nChoice:";

    
    cin >> userChoice;
    while (userChoice != 3)
    {
        cin.ignore();
        switch (userChoice)
        {
        case 1:
            cout << "\nPlease enter your Customer ID:\n";
            cin >> customerID;
            if (customerDatabase.getCustomersSize() != 0){
                if (checkIDNumber(customerDatabase, customerID, customerIndex))
                {
                    //Print a menu for a user that is in the system
                    Customer tempCustomer = customerDatabase.findCustomer(customerIndex);
                    cout << "\nWelcome back " << tempCustomer.GetCustomerName() << "!\n";
                    bool loop = false;
                    do
                    {
                        loop = false;
                        cout << "What would you like to do?\n";
                        cout << "1) Loan a movie\n2) Edit information\n3) View all current loans\n4) Delete account\nChoice:";
                        cin >> userChoice;
                        switch (userChoice)
                        {
                            case 1:
                                cout << "No\n";
                            break;

                            case 2:
                                cout << "No\n";
                            break;

                            case 3:
                                cout << "No\n";
                            break;

                            case 4:
                                customerDatabase.deleteCustomer(customerIndex);
                                //cout << (customerDatabase.findCustomer(customerIndex)).GetCustomerName() << endl;
                            break;

                        
                            default:
                                loop = true;
                                cout << "\nYou made an invalid selection. Please try again.\n\n";
                            break;
                        }
                    }while(loop);
                }
                else
                {
                    cout << "\nThere does not seem to be a customer with that ID number in the system. Please register or try again.\n";
                }
            }
            break;
        case 2:

            customerDatabase.addCustomer();
            break;

        default:
            cout << "Sorry, the choice you made was invalid. Please try again.\n";
            break;
        }
        cout << "\nMenu:" << endl;
        cout << "1) Returning Customer\n2) New Customer\n3) Exit\nChoice:";
        cin >> userChoice;
    }
}

int main()
{   
    CustomerCollection customerDatabase;
    customerDatabase.loadDataBase();
    Menu(customerDatabase);
    customerDatabase.saveDataBase();
    return 0;
}