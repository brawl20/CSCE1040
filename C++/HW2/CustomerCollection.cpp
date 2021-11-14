#include "Customer.h"
#include "CustomerCollection.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>


using namespace std;


void CustomerCollection::addCustomer()
{
    //Variables
    int customerIndex = 0;
    long long unsigned int creditCardNum;
    int expirationDateMonth;
    int expirationDateYear;
    int userChoice;
    char userName[40];
    ofstream fout;
    ifstream fin;
    string tempHolder;
    bool inSystem = false;

    cout << "Please enter your name:\n";
    cin.getline(userName, 40);
    fout.open("GreenBox-Data.txt", ios::app);
    fin.open("GreenBox-Data.txt"); 


    // Check how many Customers are in the system
    while(!fin.eof())
    {
        getline(fin, tempHolder);
        if (tempHolder == "Customer Name:")
        {
            fin.ignore();
            getline(fin,tempHolder);
            Customers.push_back(Customer());
            Customers.back().SetCustomerName(tempHolder);
            ++customerIndex;
        }
        fin.close();
    }

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
            Customers.push_back(Customer());
            fout << "Customer Name:\n" << userName << "\n";
            Customers.back().SetCustomerName(userName);

                
            // Loop if card number is invalid
            do
            {
                cout << "What is your Credit Card Number? (12 digits)" << endl;
                cin >> creditCardNum;
            }while(creditCardNum < 111111111111 || creditCardNum > 999999999999);
            fout << "Credit Card Number:\n" << creditCardNum << endl;
                
            // Loop if month isnt valid
            do
            {
                cout << "Expiration date\nMonth:\n";
                cin >> expirationDateMonth;
            }while(expirationDateMonth < 1 || expirationDateMonth > 12);
                
            // Loop if year isnt valid
            do
            {
                cout << "Year:\n";
                cin >> expirationDateYear;
            }while(expirationDateYear < 1111 || expirationDateYear > 9999);
            fout << "Expiration Date:\n" << expirationDateMonth << "/" << expirationDateYear << endl << endl;
            fout.close();
            fin.close();
        }
}
//void editCustomer(); 
//void deleteCustomer(); 
//void findCustomer(); 
//void printCustomerInfo(); 
void CustomerCollection::printCollectionEntries()
{
    for(int i = 0; i <= Customers.size(); i++)
    {
        cout << Customers[i].GetCustomerName() << endl;
    }
}
//void moviesLoaned(); 
//void printAllLoans();
