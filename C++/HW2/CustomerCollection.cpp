#include "Customer.h"
#include "CustomerCollection.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>


using namespace std;

int customerIndex = 0;

void CustomerCollection::addCustomer()
{
    //Variables
    long long unsigned int creditCardNum;
    int expirationDateMonth;
    int expirationDateYear;
    int userChoice;
    string userName;
    ofstream fout;
    ifstream fin;
    string tempHolder;
    bool inSystem = false;

    cout << "Please enter your name:\n";
    getline(cin,userName);
    fout.open("GreenBox-Data.txt", ios::app);
    fin.open("GreenBox-Data.txt"); 


    // Check how many Customers are in the system
    while(!fin.eof())
    {
        getline(fin, tempHolder);
        if (tempHolder == "Customer Name:")
        {
            getline(fin,tempHolder);
            Customers.push_back(Customer());
            Customers.back().SetCustomerName(tempHolder);
            getline(fin,tempHolder);
            ++customerIndex;
            if (tempHolder == "Credit Card Number:")
            {
                long long unsigned int cardNumber = 0;
                getline(fin,tempHolder);
                cardNumber = stoll(tempHolder, nullptr, 10);
                cout << cardNumber << endl;
                Customers.back().SetCreditCardNum(cardNumber);
            }
            getline(fin,tempHolder);
            if (tempHolder == "Expiration Date:")
            {
                getline(fin,tempHolder);
                Customers.back().SetCreditCardExpDate(tempHolder);
            }
        }
    }
    cout << "Currently have " << Customers.size() << " Customers\n";
    fin.close();

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
    cout << Customers.size() << endl;
    for(int i = 0; i < customerIndex; i++)
    {
        cout << Customers[i].GetCustomerName() << "\nCard Numbers:\n" << Customers[i].GetCreditCardNum() << endl;
    }
}
//void moviesLoaned(); 
//void printAllLoans();
