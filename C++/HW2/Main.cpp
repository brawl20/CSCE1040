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
            inSystem = false;
            cout << "Please enter your name:\n";
            cin.getline(userName, 40);
            fout.open("GreenBox-Data.txt", ios::app);
            fin.open("GreenBox-Data.txt");
            
            while(!fin.eof())
            {
                getline(fin, tempHolder);
                if (tempHolder == userName)
                {
                    inSystem = true;
                    cout << "This customer is already in our system.\n";
                    fin.close();
                    fout.close();
                }
            }
            if (!inSystem)
            {
                fout << "Customer Name:\n" << userName << "\n";
                cout << tempHolder;
                cout << userName << endl;
                fout.close();
                fin.close();
            }
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
    Menu();

    return 0;
}